/*
 *
 * This file is part of GRAMPC.
 *
 * GRAMPC - a gradient-based MPC software for real-time applications
 *
 * Copyright (C) 2014 by Bartosz Kaepernick, Knut Graichen, Tilman Utz
 * Developed at the Institute of Measurement, Control, and
 * Microtechnology, University of Ulm. All rights reserved.
 *
 * GRAMPC is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as 
 * published by the Free Software Foundation, either version 3 of 
 * the License, or (at your option) any later version.
 *
 * GRAMPC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with GRAMPC. If not, see <http://www.gnu.org/licenses/>.
 *
 */


/*
 *
 * File: euler1.c
 * Authors: Bartosz Kaepernick, Knut Graichen, Tilman Utz
 * Date: February 2014
 * Version: v1.0
 *
 * Simple euler forward integrator for GRAMPC.
 *
 */


#include "euler1.h"

void intsysEuler(typeRNum *y, typeInt pInt, typeInt Nint, typeRNum *t, typeRNum *x,
    typeRNum *u,typeGRAMPC *grampc,
    void (*pfct)(typeRNum *,typeRNum *,typeRNum *,typeRNum *,typeRNum *,typeGRAMPC *))
{
  typeInt i,j;
  typeRNum h;
  typeRNum *s = grampc->rws->rwsIntegration;

  for (j = 0; j <= Nint-2; j++) {
    if (j > 0) {
      t += pInt;
      x += pInt*grampc->param->Nx;
      u += pInt*grampc->param->Nu;
      y += pInt*grampc->param->Nx;
    }

    (*pfct)(s,y,t,x,u,grampc);

    h = t[pInt]-t[0];
    for (i = 0; i <= grampc->param->Nx-1; i++) {
      y[i+pInt*grampc->param->Nx] = y[i] + h*s[i];
    }
  }
}

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
 * File: ruku45.h
 * Authors: Bartosz Kaepernick, Knut Graichen, Tilman Utz
 * Date: February 2014
 * Version: v1.0
 *
 * HEADER FILE
 * Fourth order Runge-Kutta integrator for GRAMPC.
 *
 */


#ifndef RUKU45_H_
#define RUKU45_H_

#include "grampc_init.h"

void intsysRuKu45(typeRNum *y, typeInt pInt, typeInt Nint, typeRNum *t, typeRNum *x,
    typeRNum *u,typeGRAMPC *grampc,
    void (*pfct)(typeRNum *,typeRNum *,typeRNum *,typeRNum *,typeRNum *,typeGRAMPC *));

#endif /* RUKU45_H_ */

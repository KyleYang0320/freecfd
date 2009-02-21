/************************************************************************
	
	Copyright 2007-2009 Emre Sozer & Patrick Clark Trizila

	Contact: emresozer@freecfd.com , ptrizila@freecfd.com

	This file is a part of Free CFD

	Free CFD is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    Free CFD is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    For a copy of the GNU General Public License,
    see <http://www.gnu.org/licenses/>.

*************************************************************************/
#ifndef PETSC_FUNCTIONS_H
#define PETSC_FUNCTIONS_H

#include "petscksp.h"
#include <mpi.h>
#include <vector>
using namespace std;

#include "grid.h"
 
extern KSP ksp,ksp_turb; // linear solver context
extern Vec deltaU,deltaU_turb,rhs,rhs_turb; // solution, residual vectors
extern Mat impOP,impOP_turb; // implicit operator matrix
extern Grid grid;
extern int np, Rank;

void petsc_init(int argc, char *argv[],double rtol,double abstol,int maxits);
void petsc_solve(int &nIter,double &rNorm);
void petsc_solve_turb(int &nIter_turb, double &rNorm_turb);
void petsc_finalize(void);

#endif

/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

// define integer data types used by LAMMPS and associated size limits

// smallint = variables for system on 1 processor (nlocal, etc)
// tagint = variables for atom IDs (tag)
// bigint = variables for total system (natoms, ntimestep, etc)

// smallint must be an int, as defined by C compiler
// tagint can be 32-bit or 64-bit int, must be >= smallint
// NOTE: 64-bit tagint is not yet supported
// bigint can be 32-bit or 64-bit int, must be >= tagint

// MAXSMALLINT = max value of a smallint
// MAXTAGINT = max value of a tagint
// MAXBIGINT = max value of a bigint

// MPI_LMP_TAGINT = MPI data type corresponding to tagint
// MPI_LMP_BIGINT = MPI data type corresponding to bigint
// NOTE: you may need to set MPI_LMP_BIGINT to MPI_LONG
//       if your machine/MPI does not support "long long" data types

#ifndef LMP_LMPTYPE_H
#define LMP_LMPTYPE_H

#include "stdint.h"

namespace LAMMPS_NS {

// default settings
// 32-bit smallint and tagint, 64-bit bigint

typedef int smallint;
typedef int tagint;
typedef int64_t bigint;

#define MAXSMALLINT 0x7FFFFFFF
#define MAXTAGINT 0x7FFFFFFF
#define MAXBIGINT 0x7FFFFFFFFFFFFFFFL

#define MPI_LMP_TAGINT MPI_INT
#define MPI_LMP_BIGINT MPI_LONG_LONG

#define TAGINT_FORMAT "%d"
#define BIGINT_FORMAT "%ld"
#define TAGINT_FORMAT_NL "%d\n"
#define BIGINT_FORMAT_NL "%ld\n"

// for molecular problems that exceed 2 billion (2^31) atoms
// 32-bit smallint, 64-bit tagint and bigint
// NOTE: 64-bit tagint is not yet supported

/*
typedef int smallint;
typedef int64_t tagint;
typedef int64_t bigint;

#define MAXSMALLINT 0x7FFFFFFF
#define MAXTAGINT 0x7FFFFFFFFFFFFFFFL
#define MAXBIGINT 0x7FFFFFFFFFFFFFFFL

#define MPI_LMP_TAGINT MPI_LONG_LONG
#define MPI_LMP_BIGINT MPI_LONG_LONG

#define TAGINT_FORMAT "%ld"
#define BIGINT_FORMAT "%ld"
#define TAGINT_FORMAT_NL "%ld\n"
#define BIGINT_FORMAT_NL "%ld\n"
*/

// for machines that don't support 64-bit ints
// 32-bit smallint and tagint and bigint

/*
typedef int smallint;
typedef int tagint;
typedef int bigint;

#define MAXSMALLINT 0x7FFFFFFF
#define MAXTAGINT 0x7FFFFFFF
#define MAXBIGINT 0x7FFFFFFF

#define MPI_LMP_TAGINT MPI_INT
#define MPI_LMP_BIGINT MPI_INT

#define TAGINT_FORMAT "%d"
#define BIGINT_FORMAT "%d"
#define TAGINT_FORMAT_NL "%d\n"
#define BIGINT_FORMAT_NL "%d\n"
*/

}

#endif
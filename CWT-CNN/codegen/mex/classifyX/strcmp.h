//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  strcmp.h
//
//  Code generation for function 'strcmp'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder
{
  namespace internal
  {
    boolean_T b_strcmp(const char_T a_data[], const int32_T a_size[2], const
                       char_T b_data[], const int32_T b_size[2]);
  }
}

// End of code generation (strcmp.h)

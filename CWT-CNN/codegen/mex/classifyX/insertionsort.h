//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  insertionsort.h
//
//  Code generation for function 'insertionsort'
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

// Type Declarations
namespace coder
{
  class anonymous_function;
}

// Function Declarations
namespace coder
{
  namespace internal
  {
    void insertionsort(const emlrtStack *sp, int32_T x_data[], int32_T xend,
                       const anonymous_function *cmp);
  }
}

// End of code generation (insertionsort.h)

//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  categorical.h
//
//  Code generation for function 'categorical'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
struct cell_wrap_2
{
  coder::bounded_array<char_T, 6U, 2U> f1;
};

namespace coder
{
  class categorical
  {
   public:
    void init(const emlrtStack *sp, const cell_wrap_2 inputData[1], const
              cell_wrap_2 varargin_1_data[], const int32_T varargin_1_size[2]);
    uint64_T codes;
    bounded_array<cell_wrap_2, 5U, 1U> categoryNames;
    boolean_T isProtected;
    boolean_T isOrdinal;
  };
}

// End of code generation (categorical.h)

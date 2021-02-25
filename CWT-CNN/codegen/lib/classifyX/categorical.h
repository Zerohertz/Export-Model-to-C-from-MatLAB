//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: categorical.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Feb-2021 20:45:00
//
#ifndef CATEGORICAL_H
#define CATEGORICAL_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
struct cell_wrap_2
{
  coder::bounded_array<char, 6U, 2U> f1;
};

namespace coder
{
  class categorical
  {
   public:
    void init(const cell_wrap_2 inputData[1], const cell_wrap_2 varargin_1_data[],
              const int varargin_1_size[2]);
    categorical();
    ~categorical();
   protected:
    unsigned long long codes;
    bounded_array<cell_wrap_2, 5U, 1U> categoryNames;
    boolean_T isProtected;
    boolean_T isOrdinal;
  };
}

#endif

//
// File trailer for categorical.h
//
// [EOF]
//

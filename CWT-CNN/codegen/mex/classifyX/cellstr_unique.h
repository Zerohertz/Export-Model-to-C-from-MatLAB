//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  cellstr_unique.h
//
//  Code generation for function 'cellstr_unique'
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
struct cell_wrap_2;

// Function Declarations
namespace coder
{
  namespace matlab
  {
    namespace internal
    {
      namespace coder
      {
        namespace datatypes
        {
          void cellstr_unique(const emlrtStack *sp, const cell_wrap_2 a_data[],
                              const int32_T a_size[1], cell_wrap_2 u_data[],
                              int32_T u_size[1]);
        }
      }
    }
  }
}

// End of code generation (cellstr_unique.h)

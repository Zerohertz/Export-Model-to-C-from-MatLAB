//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  postProcessOutputToReturnCategorical.h
//
//  Code generation for function 'postProcessOutputToReturnCategorical'
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
struct cell_wrap_7;
namespace coder
{
  class categorical;
}

// Function Declarations
namespace coder
{
  void c_DeepLearningNetwork_postProce(const emlrtStack *sp, const cell_wrap_7
    scores[1], categorical processedOutput[1]);
}

// End of code generation (postProcessOutputToReturnCategorical.h)

//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  predict.h
//
//  Code generation for function 'predict'
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
class net0_0;

// Function Declarations
namespace coder
{
  void DeepLearningNetwork_predict(const emlrtStack *sp, net0_0 *obj, const
    uint8_T varargin_1[784], real32_T varargout_1[5]);
}

// End of code generation (predict.h)

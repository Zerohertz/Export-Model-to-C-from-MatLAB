//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  classifyX_mexutil.h
//
//  Code generation for function 'classifyX_mexutil'
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
void checkRunTimeError(const emlrtStack *sp, const char_T *errMsg, const char_T *
  file, uint32_T line);
emlrtRTEInfo createEmlrtInfoStruct(const char_T *file, uint32_T line);

// End of code generation (classifyX_mexutil.h)

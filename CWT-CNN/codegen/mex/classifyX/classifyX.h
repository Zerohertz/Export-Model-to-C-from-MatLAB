//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  classifyX.h
//
//  Code generation for function 'classifyX'
//


#pragma once

// Include files
#include "categorical.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void classifyX(const emlrtStack *sp, const uint8_T X[784], coder::categorical
               *label);
void classifyX_init();

// End of code generation (classifyX.h)

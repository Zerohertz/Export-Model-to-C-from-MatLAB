//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: postProcessOutputToReturnCategorical.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Feb-2021 20:45:00
//
#ifndef POSTPROCESSOUTPUTTORETURNCATEGORICAL_H
#define POSTPROCESSOUTPUTTORETURNCATEGORICAL_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct cell_wrap_7;
namespace coder
{
  class categorical;
}

// Function Declarations
namespace coder
{
  void DeepLearningNetwork_postProcessOutputToReturnCategorical(const
    cell_wrap_7 scores[1], categorical processedOutput[1]);
}

#endif

//
// File trailer for postProcessOutputToReturnCategorical.h
//
// [EOF]
//

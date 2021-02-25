//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: classifyX.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Feb-2021 20:45:00
//

// Include Files
#include "classifyX.h"
#include "DeepLearningNetwork.h"
#include "categorical.h"
#include "classifyX_data.h"
#include "classifyX_initialize.h"
#include "classifyX_internal_types.h"
#include "postProcessOutputToReturnCategorical.h"
#include "predict.h"

// Variable Definitions
static net0_0 net;
static boolean_T net_not_empty;

// Function Definitions
//
// Arguments    : const unsigned char X[784]
//                coder::categorical *label
// Return Type  : void
//
void classifyX(const unsigned char X[784], coder::categorical *label)
{
  coder::categorical labelsCell[1];
  cell_wrap_7 rv[1];
  cell_wrap_7 r;
  if (!isInitialized_classifyX) {
    classifyX_initialize();
  }

  if (!net_not_empty) {
    coder::DeepLearningNetwork_setup(&net);
    net_not_empty = true;
  }

  // cfs = cwt(X);
  // IMG = uint8(mat2gray(abs(X))*255);
  // GryMat = imresize(IMG, [28 28]);
  coder::DeepLearningNetwork_predict(&net, X, r.f1);
  rv[0] = r;
  coder::DeepLearningNetwork_postProcessOutputToReturnCategorical(rv, labelsCell);
  *label = labelsCell[0];
}

//
// Arguments    : void
// Return Type  : void
//
void classifyX_init()
{
  net_not_empty = false;
}

//
// File trailer for classifyX.cpp
//
// [EOF]
//

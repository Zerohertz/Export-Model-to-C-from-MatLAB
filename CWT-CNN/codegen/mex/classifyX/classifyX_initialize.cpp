//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  classifyX_initialize.cpp
//
//  Code generation for function 'classifyX_initialize'
//


// Include files
#include "classifyX_initialize.h"
#include "_coder_classifyX_mex.h"
#include "classifyX.h"
#include "classifyX_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

// Function Declarations
static void classifyX_once();

// Function Definitions
static void classifyX_once()
{
  mex_InitInfAndNan();

  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\classifyX.m",
                  0U, 1U, 2U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "classifyX", 0, -1, 231);

  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 202, -1, 226);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 65, -1, 111);

  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 45, 60, -1, 116);

  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  classifyX_init();
}

void classifyX_initialize()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "neural_network_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    classifyX_once();
  }
}

// End of code generation (classifyX_initialize.cpp)

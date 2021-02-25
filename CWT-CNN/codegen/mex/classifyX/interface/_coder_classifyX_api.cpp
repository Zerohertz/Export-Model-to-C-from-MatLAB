//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_classifyX_api.cpp
//
//  Code generation for function '_coder_classifyX_api'
//


// Include files
#include "_coder_classifyX_api.h"
#include "categorical.h"
#include "classifyX.h"
#include "classifyX_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[784];
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier))[784];
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[784];
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const coder::
  categorical *u);

// Function Definitions
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[784]
{
  static const int32_T dims[2] = { 28, 28 };

  uint8_T (*ret)[784];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 2U, dims);
  ret = (uint8_T (*)[784])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *X,
  const char_T *identifier))[784]
{
  emlrtMsgIdentifier thisId;
  uint8_T (*y)[784];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(X), &thisId);
  emlrtDestroyArray(&X);
  return y;
}

static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[784]
{
  uint8_T (*y)[784];
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const coder::
  categorical *u)
{
  const mxArray *propValues[5];
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *m2;
  const mxArray *m3;
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *y;
  int32_T iv[2];
  int32_T i;
  int32_T n;
  const char_T *propClasses[5] = { "matlab.internal.coder.categorical",
    "matlab.internal.coder.categorical", "matlab.internal.coder.categorical",
    "matlab.internal.coder.categorical", "matlab.internal.coder.categorical" };

  const char_T *propNames[5] = { "codes", "categoryNames", "isProtected",
    "isOrdinal", "numCategoriesUpperBound" };

  y = NULL;
  m = NULL;
  m1 = NULL;
  m2 = NULL;
  m3 = NULL;
  m4 = NULL;
  emlrtAssign(&y, emlrtCreateClassInstance("matlab.internal.coder.categorical"));
  m = NULL;
  b_y = NULL;
  m5 = emlrtCreateNumericMatrix(1, 1, mxUINT64_CLASS, mxREAL);
  *(uint64_T *)emlrtMxGetData(m5) = u->codes;
  emlrtAssign(&b_y, m5);
  emlrtAssign(&m, b_y);
  propValues[0] = m;
  m1 = NULL;
  c_y = NULL;
  emlrtAssign(&c_y, emlrtCreateCellArrayR2014a(1, u->categoryNames.size));
  i = 0;
  n = u->categoryNames.size[0];
  while (i < n) {
    d_y = NULL;
    iv[0] = u->categoryNames.data[i].f1.size[0];
    iv[1] = u->categoryNames.data[i].f1.size[1];
    m5 = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(sp, u->categoryNames.data[i].f1.size[1], m5,
      &u->categoryNames.data[i].f1.data[0]);
    emlrtAssign(&d_y, m5);
    emlrtSetCell(c_y, i, d_y);
    i++;
  }

  emlrtAssign(&m1, c_y);
  propValues[1] = m1;
  m2 = NULL;
  e_y = NULL;
  m5 = emlrtCreateLogicalScalar(u->isProtected);
  emlrtAssign(&e_y, m5);
  emlrtAssign(&m2, e_y);
  propValues[2] = m2;
  m3 = NULL;
  f_y = NULL;
  m5 = emlrtCreateLogicalScalar(u->isOrdinal);
  emlrtAssign(&f_y, m5);
  emlrtAssign(&m3, f_y);
  propValues[3] = m3;
  m4 = NULL;
  g_y = NULL;
  m5 = emlrtCreateDoubleScalar(2.81474976710654E+14);
  emlrtAssign(&g_y, m5);
  emlrtAssign(&m4, g_y);
  propValues[4] = m4;
  emlrtSetAllProperties(sp, &y, 0, 5, propNames, propClasses, propValues);
  emlrtAssign(&y, emlrtConvertInstanceToRedirectSource(sp, y, 0,
    "matlab.internal.coder.categorical"));
  return y;
}

void classifyX_api(const mxArray * const prhs[1], const mxArray *plhs[1])
{
  coder::categorical label;
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  uint8_T (*X)[784];
  st.tls = emlrtRootTLSGlobal;

  // Marshall function inputs
  X = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X");

  // Invoke the target function
  classifyX(&st, *X, &label);

  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(&st, &label);
}

// End of code generation (_coder_classifyX_api.cpp)

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_classifyX_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 16-Feb-2021 10:17:26
 */

#ifndef _CODER_CLASSIFYX_API_H
#define _CODER_CLASSIFYX_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_char_T_1x6
#define struct_emxArray_char_T_1x6

struct emxArray_char_T_1x6
{
  char_T data[6];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_char_T_1x6*/

#ifndef typedef_emxArray_char_T_1x6
#define typedef_emxArray_char_T_1x6

typedef struct emxArray_char_T_1x6 emxArray_char_T_1x6;

#endif                                 /*typedef_emxArray_char_T_1x6*/

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0

typedef struct {
  emxArray_char_T_1x6 f1;
} cell_wrap_0;

#endif                                 /*typedef_cell_wrap_0*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void classifyX(real_T X, cell_wrap_0 label[1]);
  void classifyX_api(const mxArray * const prhs[1], const mxArray *plhs[1]);
  void classifyX_atexit(void);
  void classifyX_initialize(void);
  void classifyX_terminate(void);
  void classifyX_xil_shutdown(void);
  void classifyX_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_classifyX_api.h
 *
 * [EOF]
 */

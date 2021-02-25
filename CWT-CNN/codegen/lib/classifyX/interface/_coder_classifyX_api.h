/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_classifyX_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 24-Feb-2021 20:45:00
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

#ifndef typedef_cell_wrap_2
#define typedef_cell_wrap_2

typedef struct {
  emxArray_char_T_1x6 f1;
} cell_wrap_2;

#endif                                 /*typedef_cell_wrap_2*/

#ifndef typedef_emxArray_cell_wrap_2_5
#define typedef_emxArray_cell_wrap_2_5

typedef struct {
  cell_wrap_2 data[5];
  int32_T size[1];
} emxArray_cell_wrap_2_5;

#endif                                 /*typedef_emxArray_cell_wrap_2_5*/

#ifndef struct_categorical_tag_0
#define struct_categorical_tag_0

struct categorical_tag_0
{
  uint64_T codes;
  emxArray_cell_wrap_2_5 categoryNames;
  boolean_T isProtected;
  boolean_T isOrdinal;
};

#endif                                 /*struct_categorical_tag_0*/

#ifndef typedef_categorical
#define typedef_categorical

typedef struct categorical_tag_0 categorical;

#endif                                 /*typedef_categorical*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void classifyX(uint8_T X[784], categorical *label);
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

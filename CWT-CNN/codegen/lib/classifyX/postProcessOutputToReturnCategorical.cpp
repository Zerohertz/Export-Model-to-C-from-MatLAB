//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: postProcessOutputToReturnCategorical.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Feb-2021 20:45:00
//

// Include Files
#include "postProcessOutputToReturnCategorical.h"
#include "categorical.h"
#include "classifyX_internal_types.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const cell_wrap_7 scores[1]
//                categorical processedOutput[1]
// Return Type  : void
//
namespace coder
{
  void DeepLearningNetwork_postProcessOutputToReturnCategorical(const
    cell_wrap_7 scores[1], categorical processedOutput[1])
  {
    static const char classNames[30]{
      'F', 'F', 'F', 'F', 'N', '1', '2', '3', '4', 'o', '\x00', '\x00', '\x00',
        '\x00', 'r', '\x00', '\x00', '\x00', '\x00', 'm', '\x00', '\x00', '\x00',
        '\x00', 'a', '\x00', '\x00', '\x00', '\x00', 'l'
    };

    bounded_array<cell_wrap_2, 5U, 2U> labelsCells;
    cell_wrap_2 predictedClassNames[1];
    int b_i;
    int i;
    int iindx;
    int k;
    char v_data[6];
    if (!std::isnan(scores[0].f1[0])) {
      i = 1;
    } else {
      boolean_T exitg1;
      i = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 6)) {
        if (!std::isnan(scores[0].f1[k - 1])) {
          i = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (i == 0) {
      iindx = 0;
    } else {
      float ex;
      ex = scores[0].f1[i - 1];
      iindx = i - 1;
      b_i = i + 1;
      for (k = b_i; k < 6; k++) {
        float f;
        f = scores[0].f1[k - 1];
        if (ex < f) {
          ex = f;
          iindx = k - 1;
        }
      }
    }

    labelsCells.size[0] = 1;
    labelsCells.size[1] = 0;
    for (int c_i = 0; c_i < 5; c_i++) {
      int n;
      n = 0;
      i = -1;
      for (k = 0; k < 6; k++) {
        char c;
        c = classNames[c_i + 5 * k];
        if (c != 0) {
          n++;
          i++;
          v_data[i] = c;
        }
      }

      i = labelsCells.size[1] + 1;
      labelsCells.size[0] = 1;
      labelsCells.size[1]++;
      labelsCells.data[labelsCells.size[1] - 1].f1.size[0] = 1;
      labelsCells.data[i - 1].f1.size[1] = n;
      for (b_i = 0; b_i < n; b_i++) {
        labelsCells.data[i - 1].f1.data[b_i] = v_data[b_i];
      }
    }

    predictedClassNames[0].f1.size[0] = 1;
    predictedClassNames[0].f1.size[1] = labelsCells.data[iindx].f1.size[1];
    i = labelsCells.data[iindx].f1.size[0] * labelsCells.data[iindx].f1.size[1];
    for (b_i = 0; b_i < i; b_i++) {
      predictedClassNames[0].f1.data[b_i] = labelsCells.data[iindx].f1.data[b_i];
    }

    processedOutput[0].init(predictedClassNames, labelsCells.data,
      labelsCells.size);
  }
}

//
// File trailer for postProcessOutputToReturnCategorical.cpp
//
// [EOF]
//

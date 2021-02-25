//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: categorical.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Feb-2021 20:45:00
//

// Include Files
#include "categorical.h"
#include "anonymous_function.h"
#include "introsort.h"
#include "strcmp.h"
#include "strtrim.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder
{
  categorical::categorical()
  {
  }

  //
  // Arguments    : void
  // Return Type  : void
  //
  categorical::~categorical()
  {
  }

  //
  // Arguments    : const cell_wrap_2 inputData[1]
  //                const cell_wrap_2 varargin_1_data[]
  //                const int varargin_1_size[2]
  // Return Type  : void
  //
  void categorical::init(const cell_wrap_2 inputData[1], const cell_wrap_2
    varargin_1_data[], const int varargin_1_size[2])
  {
    anonymous_function b_this;
    bounded_array<cell_wrap_2, 5U, 2U> r;
    cell_wrap_2 inData[1];
    int idx_data[5];
    int y_data[5];
    int i;
    int k;
    int n;
    int yk;
    boolean_T exitg1;
    this->isOrdinal = false;
    this->isProtected = false;
    strtrim(inputData[0].f1.data, inputData[0].f1.size, inData[0].f1.data,
            inData[0].f1.size);
    if (varargin_1_size[1] != 0) {
      r.size[0] = varargin_1_size[0];
      r.size[1] = varargin_1_size[1];
      k = varargin_1_size[1];
      for (i = 0; i < k; i++) {
        strtrim(varargin_1_data[i].f1.data, varargin_1_data[i].f1.size, r.data[i]
                .f1.data, r.data[i].f1.size);
      }

      b_this.tunableEnvironment[0].f1.size[0] = varargin_1_size[1];
      n = varargin_1_size[1];
      for (k = 0; k < n; k++) {
        b_this.tunableEnvironment[0].f1.data[k] = r.data[k];
      }
    } else {
      b_this.tunableEnvironment[0].f1.size[0] = 0;
    }

    if (b_this.tunableEnvironment[0].f1.size[0] != 0) {
      n = b_this.tunableEnvironment[0].f1.size[0];
      i = b_this.tunableEnvironment[0].f1.size[0];
      y_data[0] = 1;
      yk = 1;
      for (k = 2; k <= n; k++) {
        yk++;
        y_data[k - 1] = yk;
      }

      if (0 <= i - 1) {
        std::memcpy(&idx_data[0], &y_data[0], i * sizeof(int));
      }

      internal::introsort(idx_data, b_this.tunableEnvironment[0].f1.size[0],
                          &b_this);
    }

    if (b_this.tunableEnvironment[0].f1.size[0] != 0) {
      k = b_this.tunableEnvironment[0].f1.size[0];
      this->categoryNames.size[0] = b_this.tunableEnvironment[0].f1.size[0];
      for (i = 0; i < k; i++) {
        this->categoryNames.data[i].f1.size[0] = 1;
        yk = b_this.tunableEnvironment[0].f1.data[i].f1.size[1];
        this->categoryNames.data[i].f1.size[1] = yk;
        n = b_this.tunableEnvironment[0].f1.data[i].f1.size[0] * yk;
        for (yk = 0; yk < n; yk++) {
          this->categoryNames.data[i].f1.data[yk] = b_this.tunableEnvironment[0]
            .f1.data[i].f1.data[yk];
        }
      }
    } else {
      this->categoryNames.size[0] = 0;
    }

    k = 0;
    n = 0;
    exitg1 = false;
    while ((!exitg1) && (n <= b_this.tunableEnvironment[0].f1.size[0] - 1)) {
      if (internal::b_strcmp(inData[0].f1.data, inData[0].f1.size,
                             b_this.tunableEnvironment[0].f1.data[n].f1.data,
                             b_this.tunableEnvironment[0].f1.data[n].f1.size)) {
        k = n + 1;
        exitg1 = true;
      } else {
        n++;
      }
    }

    if (k < 0) {
      k = 0;
    }

    this->codes = static_cast<unsigned long long>(k);
  }
}

//
// File trailer for categorical.cpp
//
// [EOF]
//

/*
    Copyright (c) 2016, Taiga Nomi, Edgar Riba
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once

#include "tiny_dnn/core/kernels/fully_connected_op_internal.h"

namespace tiny_dnn {
namespace kernels {

inline void
fully_connected_op_avx(const tensor_t& in_data,
                       const vec_t&    W,
                       const vec_t&    bias,
                       tensor_t&       out_data,
                       const fully_params& params,
                       const bool      layer_parallelize) {
#ifdef CNN_USE_AVX
    // TODO(nyanp/beru): is this really AVX ??
    fully_connected_op_internal(
        in_data,
        W,
        bias,
        out_data,
        params,
        layer_parallelize);
#else
    CNN_UNREFERENCED_PARAMETER(in_data);
    CNN_UNREFERENCED_PARAMETER(W);
    CNN_UNREFERENCED_PARAMETER(bias);
    CNN_UNREFERENCED_PARAMETER(out_data);
    CNN_UNREFERENCED_PARAMETER(params);
    CNN_UNREFERENCED_PARAMETER(layer_parallelize);
    throw nn_error("TinyDNN has not been compiled with AVX support.");
#endif
}

inline void
fully_connected_op_avx(const tensor_t& prev_out,
                       const vec_t&    W,
                       tensor_t&       dW,
                       tensor_t&       db,
                       tensor_t&       curr_delta,
                       tensor_t&       prev_delta,
                       const fully_params& params,
                       const bool      layer_parallelize) {
#ifdef CNN_USE_AVX
    // TODO(nyanp/beru): is this really AVX ??
    fully_connected_op_internal(
        prev_out,
        W,
        dW,
        db,
        curr_delta,
        prev_delta,
        params,
        layer_parallelize);
#else
    CNN_UNREFERENCED_PARAMETER(prev_out);
    CNN_UNREFERENCED_PARAMETER(W);
    CNN_UNREFERENCED_PARAMETER(dW);
    CNN_UNREFERENCED_PARAMETER(db);
    CNN_UNREFERENCED_PARAMETER(curr_delta);
    CNN_UNREFERENCED_PARAMETER(prev_delta);
    CNN_UNREFERENCED_PARAMETER(params);
    CNN_UNREFERENCED_PARAMETER(layer_parallelize);
    throw nn_error("TinyDNN has not been compiled with AVX support.");
#endif

}

}  // namespace kernels
}  // namespace tiny_dnn

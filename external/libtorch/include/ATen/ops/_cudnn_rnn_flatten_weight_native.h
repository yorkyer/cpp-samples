#pragma once

// @generated by torchgen/gen.py from NativeFunction.h

#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>
#include <c10/core/QScheme.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <tuple>
#include <vector>


namespace at {
namespace native {
TORCH_API at::Tensor & _cudnn_rnn_flatten_weight_out(at::TensorList weight_arr, int64_t weight_stride0, int64_t input_size, int64_t mode, int64_t hidden_size, int64_t proj_size, int64_t num_layers, bool batch_first, bool bidirectional, at::Tensor & out);
TORCH_API at::Tensor _cudnn_rnn_flatten_weight(at::TensorList weight_arr, int64_t weight_stride0, int64_t input_size, int64_t mode, int64_t hidden_size, int64_t proj_size, int64_t num_layers, bool batch_first, bool bidirectional);
} // namespace native
} // namespace at

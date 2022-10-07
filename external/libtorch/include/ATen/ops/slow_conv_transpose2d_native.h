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
#include <ATen/ops/slow_conv_transpose2d_meta.h>

namespace at {
namespace native {
struct TORCH_API structured_slow_conv_transpose2d_structured_cpu : public at::meta::structured_slow_conv_transpose2d {
void impl(const at::Tensor & self, const at::Tensor & weight, at::IntArrayRef kernel_size, at::OptionalTensorRef bias, at::IntArrayRef stride, at::IntArrayRef padding, at::IntArrayRef output_padding, at::IntArrayRef dilation, const at::Tensor & out);
};
struct TORCH_API structured_slow_conv_transpose2d_structured_cuda : public at::meta::structured_slow_conv_transpose2d {
void impl(const at::Tensor & self, const at::Tensor & weight, at::IntArrayRef kernel_size, at::OptionalTensorRef bias, at::IntArrayRef stride, at::IntArrayRef padding, at::IntArrayRef output_padding, at::IntArrayRef dilation, const at::Tensor & out);
};
} // namespace native
} // namespace at

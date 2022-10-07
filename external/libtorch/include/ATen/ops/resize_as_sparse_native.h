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
TORCH_API at::Tensor resize_as_sparse(const at::Tensor & self, const at::Tensor & the_template);
TORCH_API const at::Tensor & resize_as_sparse_out(const at::Tensor & self, const at::Tensor & the_template, const at::Tensor & out);
TORCH_API const at::Tensor & resize_as_sparse_(const at::Tensor & self, const at::Tensor & the_template);
TORCH_API const at::Tensor & resize_as_sparse_csr_(const at::Tensor & self, const at::Tensor & the_template);
} // namespace native
} // namespace at

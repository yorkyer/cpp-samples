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
TORCH_API at::Tensor randint(int64_t high, at::IntArrayRef size, c10::optional<at::ScalarType> dtype={}, c10::optional<at::Layout> layout={}, c10::optional<at::Device> device={}, c10::optional<bool> pin_memory={});
TORCH_API at::Tensor & randint_out(int64_t high, at::IntArrayRef size, at::Tensor & out);
TORCH_API at::Tensor randint(int64_t high, at::IntArrayRef size, c10::optional<at::Generator> generator, c10::optional<at::ScalarType> dtype={}, c10::optional<at::Layout> layout={}, c10::optional<at::Device> device={}, c10::optional<bool> pin_memory={});
TORCH_API at::Tensor & randint_out(int64_t high, at::IntArrayRef size, c10::optional<at::Generator> generator, at::Tensor & out);
TORCH_API at::Tensor randint(int64_t low, int64_t high, at::IntArrayRef size, c10::optional<at::ScalarType> dtype={}, c10::optional<at::Layout> layout={}, c10::optional<at::Device> device={}, c10::optional<bool> pin_memory={});
TORCH_API at::Tensor & randint_out(int64_t low, int64_t high, at::IntArrayRef size, at::Tensor & out);
TORCH_API at::Tensor randint(int64_t low, int64_t high, at::IntArrayRef size, c10::optional<at::Generator> generator, c10::optional<at::ScalarType> dtype={}, c10::optional<at::Layout> layout={}, c10::optional<at::Device> device={}, c10::optional<bool> pin_memory={});
TORCH_API at::Tensor & randint_out(int64_t low, int64_t high, at::IntArrayRef size, c10::optional<at::Generator> generator, at::Tensor & out);
} // namespace native
} // namespace at

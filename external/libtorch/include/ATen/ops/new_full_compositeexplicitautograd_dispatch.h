#pragma once
// @generated by torchgen/gen.py from DispatchKeyFunction.h

// NB: The implementing C++ file is RegisterDispatchKey.cpp

// The only #includes we need are for custom classes that have defaults in the C++ API
#include <c10/core/MemoryFormat.h>
#include <c10/core/Scalar.h>
#include <ATen/core/Reduction.h>

// Forward declarations of any types needed in the operator signatures.
// We can't directly include these classes because it will cause circular include dependencies.
// This file is included by TensorBody.h, which defines the Tensor class.
#include <ATen/core/ATen_fwd.h>

namespace at {

namespace compositeexplicitautograd {

TORCH_API at::Tensor new_full(const at::Tensor & self, at::IntArrayRef size, const at::Scalar & fill_value, at::TensorOptions options={});
TORCH_API at::Tensor new_full(const at::Tensor & self, at::IntArrayRef size, const at::Scalar & fill_value, c10::optional<at::ScalarType> dtype, c10::optional<at::Layout> layout, c10::optional<at::Device> device, c10::optional<bool> pin_memory);
TORCH_API at::Tensor & new_full_out(at::Tensor & out, const at::Tensor & self, at::IntArrayRef size, const at::Scalar & fill_value);
TORCH_API at::Tensor & new_full_outf(const at::Tensor & self, at::IntArrayRef size, const at::Scalar & fill_value, at::Tensor & out);

} // namespace compositeexplicitautograd
} // namespace at

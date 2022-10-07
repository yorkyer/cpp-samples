#pragma once

// @generated by torchgen/gen.py from Function.h

#include <ATen/Context.h>
#include <ATen/DeviceGuard.h>
#include <ATen/TensorUtils.h>
#include <ATen/TracerMode.h>
#include <ATen/core/Generator.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>



#include <ATen/ops/new_full_ops.h>

namespace at {


// aten::new_full.out(Tensor self, int[] size, Scalar fill_value, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & new_full_out(at::Tensor & out, const at::Tensor & self, at::IntArrayRef size, const at::Scalar & fill_value) {
    return at::_ops::new_full_out::call(self, size, fill_value, out);
}

// aten::new_full.out(Tensor self, int[] size, Scalar fill_value, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & new_full_outf(const at::Tensor & self, at::IntArrayRef size, const at::Scalar & fill_value, at::Tensor & out) {
    return at::_ops::new_full_out::call(self, size, fill_value, out);
}

}

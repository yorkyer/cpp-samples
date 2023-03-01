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



#include <ATen/ops/new_empty_strided_ops.h>

namespace at {


// aten::new_empty_strided.out(Tensor self, int[] size, int[] stride, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & new_empty_strided_out(at::Tensor & out, const at::Tensor & self, at::IntArrayRef size, at::IntArrayRef stride) {
    return at::_ops::new_empty_strided_out::call(self, size, stride, out);
}

// aten::new_empty_strided.out(Tensor self, int[] size, int[] stride, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & new_empty_strided_outf(const at::Tensor & self, at::IntArrayRef size, at::IntArrayRef stride, at::Tensor & out) {
    return at::_ops::new_empty_strided_out::call(self, size, stride, out);
}

}
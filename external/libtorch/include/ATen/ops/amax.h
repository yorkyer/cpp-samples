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



#include <ATen/ops/amax_ops.h>

namespace at {


// aten::amax(Tensor self, int[1] dim=[], bool keepdim=False) -> Tensor
inline at::Tensor amax(const at::Tensor & self, at::IntArrayRef dim={}, bool keepdim=false) {
    return at::_ops::amax::call(self, dim, keepdim);
}

// aten::amax.out(Tensor self, int[1] dim=[], bool keepdim=False, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & amax_out(at::Tensor & out, const at::Tensor & self, at::IntArrayRef dim={}, bool keepdim=false) {
    return at::_ops::amax_out::call(self, dim, keepdim, out);
}

// aten::amax.out(Tensor self, int[1] dim=[], bool keepdim=False, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & amax_outf(const at::Tensor & self, at::IntArrayRef dim, bool keepdim, at::Tensor & out) {
    return at::_ops::amax_out::call(self, dim, keepdim, out);
}

}

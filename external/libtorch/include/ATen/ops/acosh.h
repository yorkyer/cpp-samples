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



#include <ATen/ops/acosh_ops.h>

namespace at {


// aten::acosh(Tensor self) -> Tensor
inline at::Tensor acosh(const at::Tensor & self) {
    return at::_ops::acosh::call(self);
}

// aten::acosh_(Tensor(a!) self) -> Tensor(a!)
inline at::Tensor & acosh_(at::Tensor & self) {
    return at::_ops::acosh_::call(self);
}

// aten::acosh.out(Tensor self, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & acosh_out(at::Tensor & out, const at::Tensor & self) {
    return at::_ops::acosh_out::call(self, out);
}

// aten::acosh.out(Tensor self, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & acosh_outf(const at::Tensor & self, at::Tensor & out) {
    return at::_ops::acosh_out::call(self, out);
}

}

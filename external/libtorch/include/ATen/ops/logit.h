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



#include <ATen/ops/logit_ops.h>

namespace at {


// aten::logit(Tensor self, float? eps=None) -> Tensor
inline at::Tensor logit(const at::Tensor & self, c10::optional<double> eps=c10::nullopt) {
    return at::_ops::logit::call(self, eps);
}

// aten::logit_(Tensor(a!) self, float? eps=None) -> Tensor(a!)
inline at::Tensor & logit_(at::Tensor & self, c10::optional<double> eps=c10::nullopt) {
    return at::_ops::logit_::call(self, eps);
}

// aten::logit.out(Tensor self, float? eps=None, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & logit_out(at::Tensor & out, const at::Tensor & self, c10::optional<double> eps=c10::nullopt) {
    return at::_ops::logit_out::call(self, eps, out);
}

// aten::logit.out(Tensor self, float? eps=None, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & logit_outf(const at::Tensor & self, c10::optional<double> eps, at::Tensor & out) {
    return at::_ops::logit_out::call(self, eps, out);
}

}

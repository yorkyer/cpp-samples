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



#include <ATen/ops/avg_pool2d_ops.h>

namespace at {


// aten::avg_pool2d.out(Tensor self, int[2] kernel_size, int[2] stride=[], int[2] padding=0, bool ceil_mode=False, bool count_include_pad=True, int? divisor_override=None, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & avg_pool2d_out(at::Tensor & out, const at::Tensor & self, at::IntArrayRef kernel_size, at::IntArrayRef stride={}, at::IntArrayRef padding=0, bool ceil_mode=false, bool count_include_pad=true, c10::optional<int64_t> divisor_override=c10::nullopt) {
    return at::_ops::avg_pool2d_out::call(self, kernel_size, stride, padding, ceil_mode, count_include_pad, divisor_override, out);
}

// aten::avg_pool2d.out(Tensor self, int[2] kernel_size, int[2] stride=[], int[2] padding=0, bool ceil_mode=False, bool count_include_pad=True, int? divisor_override=None, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & avg_pool2d_outf(const at::Tensor & self, at::IntArrayRef kernel_size, at::IntArrayRef stride, at::IntArrayRef padding, bool ceil_mode, bool count_include_pad, c10::optional<int64_t> divisor_override, at::Tensor & out) {
    return at::_ops::avg_pool2d_out::call(self, kernel_size, stride, padding, ceil_mode, count_include_pad, divisor_override, out);
}

// aten::avg_pool2d(Tensor self, int[2] kernel_size, int[2] stride=[], int[2] padding=0, bool ceil_mode=False, bool count_include_pad=True, int? divisor_override=None) -> Tensor
inline at::Tensor avg_pool2d(const at::Tensor & self, at::IntArrayRef kernel_size, at::IntArrayRef stride={}, at::IntArrayRef padding=0, bool ceil_mode=false, bool count_include_pad=true, c10::optional<int64_t> divisor_override=c10::nullopt) {
    return at::_ops::avg_pool2d::call(self, kernel_size, stride, padding, ceil_mode, count_include_pad, divisor_override);
}

}

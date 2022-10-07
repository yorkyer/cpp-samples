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



#include <ATen/ops/slice_scatter_ops.h>

namespace at {


// aten::slice_scatter(Tensor self, Tensor src, int dim=0, int? start=None, int? end=None, int step=1) -> Tensor
inline at::Tensor slice_scatter(const at::Tensor & self, const at::Tensor & src, int64_t dim=0, c10::optional<int64_t> start=c10::nullopt, c10::optional<int64_t> end=c10::nullopt, int64_t step=1) {
    return at::_ops::slice_scatter::call(self, src, dim, start, end, step);
}

// aten::slice_scatter.out(Tensor self, Tensor src, int dim=0, int? start=None, int? end=None, int step=1, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & slice_scatter_out(at::Tensor & out, const at::Tensor & self, const at::Tensor & src, int64_t dim=0, c10::optional<int64_t> start=c10::nullopt, c10::optional<int64_t> end=c10::nullopt, int64_t step=1) {
    return at::_ops::slice_scatter_out::call(self, src, dim, start, end, step, out);
}

// aten::slice_scatter.out(Tensor self, Tensor src, int dim=0, int? start=None, int? end=None, int step=1, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & slice_scatter_outf(const at::Tensor & self, const at::Tensor & src, int64_t dim, c10::optional<int64_t> start, c10::optional<int64_t> end, int64_t step, at::Tensor & out) {
    return at::_ops::slice_scatter_out::call(self, src, dim, start, end, step, out);
}

}

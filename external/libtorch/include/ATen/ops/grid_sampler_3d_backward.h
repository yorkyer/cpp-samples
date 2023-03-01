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



#include <ATen/ops/grid_sampler_3d_backward_ops.h>

namespace at {


// aten::grid_sampler_3d_backward(Tensor grad_output, Tensor input, Tensor grid, int interpolation_mode, int padding_mode, bool align_corners, bool[2] output_mask) -> (Tensor, Tensor)
inline ::std::tuple<at::Tensor,at::Tensor> grid_sampler_3d_backward(const at::Tensor & grad_output, const at::Tensor & input, const at::Tensor & grid, int64_t interpolation_mode, int64_t padding_mode, bool align_corners, ::std::array<bool,2> output_mask) {
    return at::_ops::grid_sampler_3d_backward::call(grad_output, input, grid, interpolation_mode, padding_mode, align_corners, output_mask);
}

// aten::grid_sampler_3d_backward.out(Tensor grad_output, Tensor input, Tensor grid, int interpolation_mode, int padding_mode, bool align_corners, bool[2] output_mask, *, Tensor(a!) out0, Tensor(b!) out1) -> (Tensor(a!), Tensor(b!))
inline ::std::tuple<at::Tensor &,at::Tensor &> grid_sampler_3d_backward_out(at::Tensor & out0, at::Tensor & out1, const at::Tensor & grad_output, const at::Tensor & input, const at::Tensor & grid, int64_t interpolation_mode, int64_t padding_mode, bool align_corners, ::std::array<bool,2> output_mask) {
    return at::_ops::grid_sampler_3d_backward_out::call(grad_output, input, grid, interpolation_mode, padding_mode, align_corners, output_mask, out0, out1);
}

// aten::grid_sampler_3d_backward.out(Tensor grad_output, Tensor input, Tensor grid, int interpolation_mode, int padding_mode, bool align_corners, bool[2] output_mask, *, Tensor(a!) out0, Tensor(b!) out1) -> (Tensor(a!), Tensor(b!))
inline ::std::tuple<at::Tensor &,at::Tensor &> grid_sampler_3d_backward_outf(const at::Tensor & grad_output, const at::Tensor & input, const at::Tensor & grid, int64_t interpolation_mode, int64_t padding_mode, bool align_corners, ::std::array<bool,2> output_mask, at::Tensor & out0, at::Tensor & out1) {
    return at::_ops::grid_sampler_3d_backward_out::call(grad_output, input, grid, interpolation_mode, padding_mode, align_corners, output_mask, out0, out1);
}

}
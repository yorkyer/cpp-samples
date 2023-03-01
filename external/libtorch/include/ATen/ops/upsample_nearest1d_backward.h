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



#include <ATen/ops/upsample_nearest1d_backward_ops.h>

namespace at {


// aten::upsample_nearest1d_backward.vec(Tensor grad_output, int[]? output_size, int[] input_size, float[]? scale_factors) -> Tensor
inline at::Tensor upsample_nearest1d_backward(const at::Tensor & grad_output, at::OptionalIntArrayRef output_size, at::IntArrayRef input_size, c10::optional<at::ArrayRef<double>> scale_factors) {
    return at::_ops::upsample_nearest1d_backward_vec::call(grad_output, output_size, input_size, scale_factors);
}

// aten::upsample_nearest1d_backward.grad_input(Tensor grad_output, int[1] output_size, int[3] input_size, float? scales=None, *, Tensor(a!) grad_input) -> Tensor(a!)
inline at::Tensor & upsample_nearest1d_backward_out(at::Tensor & grad_input, const at::Tensor & grad_output, at::IntArrayRef output_size, at::IntArrayRef input_size, c10::optional<double> scales=c10::nullopt) {
    return at::_ops::upsample_nearest1d_backward_grad_input::call(grad_output, output_size, input_size, scales, grad_input);
}

// aten::upsample_nearest1d_backward.grad_input(Tensor grad_output, int[1] output_size, int[3] input_size, float? scales=None, *, Tensor(a!) grad_input) -> Tensor(a!)
inline at::Tensor & upsample_nearest1d_backward_outf(const at::Tensor & grad_output, at::IntArrayRef output_size, at::IntArrayRef input_size, c10::optional<double> scales, at::Tensor & grad_input) {
    return at::_ops::upsample_nearest1d_backward_grad_input::call(grad_output, output_size, input_size, scales, grad_input);
}

// aten::upsample_nearest1d_backward(Tensor grad_output, int[1] output_size, int[3] input_size, float? scales=None) -> Tensor
inline at::Tensor upsample_nearest1d_backward(const at::Tensor & grad_output, at::IntArrayRef output_size, at::IntArrayRef input_size, c10::optional<double> scales=c10::nullopt) {
    return at::_ops::upsample_nearest1d_backward::call(grad_output, output_size, input_size, scales);
}

// aten::upsample_nearest1d_backward.vec_out(Tensor grad_output, int[]? output_size, int[] input_size, float[]? scale_factors, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & upsample_nearest1d_backward_out(at::Tensor & out, const at::Tensor & grad_output, at::OptionalIntArrayRef output_size, at::IntArrayRef input_size, c10::optional<at::ArrayRef<double>> scale_factors) {
    return at::_ops::upsample_nearest1d_backward_vec_out::call(grad_output, output_size, input_size, scale_factors, out);
}

// aten::upsample_nearest1d_backward.vec_out(Tensor grad_output, int[]? output_size, int[] input_size, float[]? scale_factors, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & upsample_nearest1d_backward_outf(const at::Tensor & grad_output, at::OptionalIntArrayRef output_size, at::IntArrayRef input_size, c10::optional<at::ArrayRef<double>> scale_factors, at::Tensor & out) {
    return at::_ops::upsample_nearest1d_backward_vec_out::call(grad_output, output_size, input_size, scale_factors, out);
}

}
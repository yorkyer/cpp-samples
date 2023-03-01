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



#include <ATen/ops/_ctc_loss_ops.h>

namespace at {


// aten::_ctc_loss(Tensor log_probs, Tensor targets, int[] input_lengths, int[] target_lengths, int blank=0, bool zero_infinity=False) -> (Tensor, Tensor)
inline ::std::tuple<at::Tensor,at::Tensor> _ctc_loss(const at::Tensor & log_probs, const at::Tensor & targets, at::IntArrayRef input_lengths, at::IntArrayRef target_lengths, int64_t blank=0, bool zero_infinity=false) {
    return at::_ops::_ctc_loss::call(log_probs, targets, input_lengths, target_lengths, blank, zero_infinity);
}

// aten::_ctc_loss.out(Tensor log_probs, Tensor targets, int[] input_lengths, int[] target_lengths, int blank=0, bool zero_infinity=False, *, Tensor(a!) out0, Tensor(b!) out1) -> (Tensor(a!), Tensor(b!))
inline ::std::tuple<at::Tensor &,at::Tensor &> _ctc_loss_out(at::Tensor & out0, at::Tensor & out1, const at::Tensor & log_probs, const at::Tensor & targets, at::IntArrayRef input_lengths, at::IntArrayRef target_lengths, int64_t blank=0, bool zero_infinity=false) {
    return at::_ops::_ctc_loss_out::call(log_probs, targets, input_lengths, target_lengths, blank, zero_infinity, out0, out1);
}

// aten::_ctc_loss.out(Tensor log_probs, Tensor targets, int[] input_lengths, int[] target_lengths, int blank=0, bool zero_infinity=False, *, Tensor(a!) out0, Tensor(b!) out1) -> (Tensor(a!), Tensor(b!))
inline ::std::tuple<at::Tensor &,at::Tensor &> _ctc_loss_outf(const at::Tensor & log_probs, const at::Tensor & targets, at::IntArrayRef input_lengths, at::IntArrayRef target_lengths, int64_t blank, bool zero_infinity, at::Tensor & out0, at::Tensor & out1) {
    return at::_ops::_ctc_loss_out::call(log_probs, targets, input_lengths, target_lengths, blank, zero_infinity, out0, out1);
}

}
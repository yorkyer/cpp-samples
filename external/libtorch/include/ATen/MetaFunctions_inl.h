#pragma once
// @generated by torchgen/gen.py from DispatchKeyFunctions_inl.h

// NB: The implementing C++ file is RegisterDispatchKey.cpp

// The only #includes we need are for custom classes that have defaults in the C++ API
#include <c10/core/MemoryFormat.h>
#include <c10/core/Scalar.h>
#include <ATen/core/Reduction.h>

#if defined(AT_PER_OPERATOR_HEADERS) && defined(TORCH_ASSERT_ONLY_METHOD_OPERATORS)
#error This change adds a dependency on all pytorch operators, meaning the     \
  file will need to be re-compiled every time an operator is changed or added. \
  Consider including a specific operator from                                  \
  <ATen/ops/{my_operator}_meta_dispatch.h>.                   \
  See NOTE [TORCH_ASSERT_ONLY_METHOD_OPERATORS].
#endif

#include <ATen/ops/_add_relu_meta_dispatch.h>
#include <ATen/ops/_addmm_activation_meta_dispatch.h>
#include <ATen/ops/_amp_update_scale_meta_dispatch.h>
#include <ATen/ops/_coalesced_meta_dispatch.h>
#include <ATen/ops/_convert_indices_from_coo_to_csr_meta_dispatch.h>
#include <ATen/ops/_convert_indices_from_csr_to_coo_meta_dispatch.h>
#include <ATen/ops/_index_put_impl_meta_dispatch.h>
#include <ATen/ops/_linalg_det_meta_dispatch.h>
#include <ATen/ops/_linalg_eigh_meta_dispatch.h>
#include <ATen/ops/_linalg_slogdet_meta_dispatch.h>
#include <ATen/ops/_linalg_solve_ex_meta_dispatch.h>
#include <ATen/ops/_linalg_svd_meta_dispatch.h>
#include <ATen/ops/_log_softmax_meta_dispatch.h>
#include <ATen/ops/_log_softmax_backward_data_meta_dispatch.h>
#include <ATen/ops/_mkldnn_transpose_meta_dispatch.h>
#include <ATen/ops/_reshape_alias_meta_dispatch.h>
#include <ATen/ops/_resize_output_meta_dispatch.h>
#include <ATen/ops/_softmax_meta_dispatch.h>
#include <ATen/ops/_softmax_backward_data_meta_dispatch.h>
#include <ATen/ops/_sparse_coo_tensor_with_dims_meta_dispatch.h>
#include <ATen/ops/_sparse_coo_tensor_with_dims_and_tensors_meta_dispatch.h>
#include <ATen/ops/_upsample_bicubic2d_aa_meta_dispatch.h>
#include <ATen/ops/_upsample_bicubic2d_aa_backward_meta_dispatch.h>
#include <ATen/ops/_upsample_bilinear2d_aa_meta_dispatch.h>
#include <ATen/ops/_upsample_bilinear2d_aa_backward_meta_dispatch.h>
#include <ATen/ops/_upsample_nearest_exact1d_meta_dispatch.h>
#include <ATen/ops/_upsample_nearest_exact1d_backward_meta_dispatch.h>
#include <ATen/ops/_upsample_nearest_exact2d_meta_dispatch.h>
#include <ATen/ops/_upsample_nearest_exact2d_backward_meta_dispatch.h>
#include <ATen/ops/_upsample_nearest_exact3d_meta_dispatch.h>
#include <ATen/ops/_upsample_nearest_exact3d_backward_meta_dispatch.h>
#include <ATen/ops/acos_meta_dispatch.h>
#include <ATen/ops/acosh_meta_dispatch.h>
#include <ATen/ops/adaptive_max_pool2d_meta_dispatch.h>
#include <ATen/ops/adaptive_max_pool2d_backward_meta_dispatch.h>
#include <ATen/ops/adaptive_max_pool3d_meta_dispatch.h>
#include <ATen/ops/adaptive_max_pool3d_backward_meta_dispatch.h>
#include <ATen/ops/add_meta_dispatch.h>
#include <ATen/ops/addbmm_meta_dispatch.h>
#include <ATen/ops/addcdiv_meta_dispatch.h>
#include <ATen/ops/addcmul_meta_dispatch.h>
#include <ATen/ops/addmm_meta_dispatch.h>
#include <ATen/ops/addmv_meta_dispatch.h>
#include <ATen/ops/all_meta_dispatch.h>
#include <ATen/ops/amax_meta_dispatch.h>
#include <ATen/ops/amin_meta_dispatch.h>
#include <ATen/ops/aminmax_meta_dispatch.h>
#include <ATen/ops/any_meta_dispatch.h>
#include <ATen/ops/arange_meta_dispatch.h>
#include <ATen/ops/argmax_meta_dispatch.h>
#include <ATen/ops/argmin_meta_dispatch.h>
#include <ATen/ops/as_strided_meta_dispatch.h>
#include <ATen/ops/asin_meta_dispatch.h>
#include <ATen/ops/asinh_meta_dispatch.h>
#include <ATen/ops/atan_meta_dispatch.h>
#include <ATen/ops/atan2_meta_dispatch.h>
#include <ATen/ops/atanh_meta_dispatch.h>
#include <ATen/ops/avg_pool2d_meta_dispatch.h>
#include <ATen/ops/avg_pool2d_backward_meta_dispatch.h>
#include <ATen/ops/avg_pool3d_meta_dispatch.h>
#include <ATen/ops/avg_pool3d_backward_meta_dispatch.h>
#include <ATen/ops/baddbmm_meta_dispatch.h>
#include <ATen/ops/bernoulli_meta_dispatch.h>
#include <ATen/ops/bitwise_and_meta_dispatch.h>
#include <ATen/ops/bitwise_left_shift_meta_dispatch.h>
#include <ATen/ops/bitwise_not_meta_dispatch.h>
#include <ATen/ops/bitwise_or_meta_dispatch.h>
#include <ATen/ops/bitwise_right_shift_meta_dispatch.h>
#include <ATen/ops/bitwise_xor_meta_dispatch.h>
#include <ATen/ops/bmm_meta_dispatch.h>
#include <ATen/ops/cat_meta_dispatch.h>
#include <ATen/ops/cauchy_meta_dispatch.h>
#include <ATen/ops/ceil_meta_dispatch.h>
#include <ATen/ops/clamp_meta_dispatch.h>
#include <ATen/ops/clamp_max_meta_dispatch.h>
#include <ATen/ops/clamp_min_meta_dispatch.h>
#include <ATen/ops/copy_sparse_to_sparse_meta_dispatch.h>
#include <ATen/ops/copysign_meta_dispatch.h>
#include <ATen/ops/cos_meta_dispatch.h>
#include <ATen/ops/cosh_meta_dispatch.h>
#include <ATen/ops/cumprod_meta_dispatch.h>
#include <ATen/ops/cumsum_meta_dispatch.h>
#include <ATen/ops/digamma_meta_dispatch.h>
#include <ATen/ops/div_meta_dispatch.h>
#include <ATen/ops/elu_meta_dispatch.h>
#include <ATen/ops/elu_backward_meta_dispatch.h>
#include <ATen/ops/embedding_renorm_meta_dispatch.h>
#include <ATen/ops/empty_meta_dispatch.h>
#include <ATen/ops/empty_strided_meta_dispatch.h>
#include <ATen/ops/eq_meta_dispatch.h>
#include <ATen/ops/erf_meta_dispatch.h>
#include <ATen/ops/erfc_meta_dispatch.h>
#include <ATen/ops/erfinv_meta_dispatch.h>
#include <ATen/ops/exp_meta_dispatch.h>
#include <ATen/ops/exp2_meta_dispatch.h>
#include <ATen/ops/expm1_meta_dispatch.h>
#include <ATen/ops/exponential_meta_dispatch.h>
#include <ATen/ops/eye_meta_dispatch.h>
#include <ATen/ops/fill_meta_dispatch.h>
#include <ATen/ops/floor_meta_dispatch.h>
#include <ATen/ops/floor_divide_meta_dispatch.h>
#include <ATen/ops/fmax_meta_dispatch.h>
#include <ATen/ops/fmin_meta_dispatch.h>
#include <ATen/ops/fmod_meta_dispatch.h>
#include <ATen/ops/frac_meta_dispatch.h>
#include <ATen/ops/fractional_max_pool2d_meta_dispatch.h>
#include <ATen/ops/fractional_max_pool2d_backward_meta_dispatch.h>
#include <ATen/ops/fractional_max_pool3d_meta_dispatch.h>
#include <ATen/ops/gather_meta_dispatch.h>
#include <ATen/ops/gcd_meta_dispatch.h>
#include <ATen/ops/ge_meta_dispatch.h>
#include <ATen/ops/gelu_meta_dispatch.h>
#include <ATen/ops/gelu_backward_meta_dispatch.h>
#include <ATen/ops/geometric_meta_dispatch.h>
#include <ATen/ops/glu_meta_dispatch.h>
#include <ATen/ops/gt_meta_dispatch.h>
#include <ATen/ops/hardshrink_meta_dispatch.h>
#include <ATen/ops/hardshrink_backward_meta_dispatch.h>
#include <ATen/ops/hardsigmoid_meta_dispatch.h>
#include <ATen/ops/hardsigmoid_backward_meta_dispatch.h>
#include <ATen/ops/hardswish_meta_dispatch.h>
#include <ATen/ops/hardtanh_meta_dispatch.h>
#include <ATen/ops/heaviside_meta_dispatch.h>
#include <ATen/ops/hypot_meta_dispatch.h>
#include <ATen/ops/i0_meta_dispatch.h>
#include <ATen/ops/igamma_meta_dispatch.h>
#include <ATen/ops/igammac_meta_dispatch.h>
#include <ATen/ops/index_meta_dispatch.h>
#include <ATen/ops/index_add_meta_dispatch.h>
#include <ATen/ops/index_copy_meta_dispatch.h>
#include <ATen/ops/index_fill_meta_dispatch.h>
#include <ATen/ops/index_reduce_meta_dispatch.h>
#include <ATen/ops/isin_meta_dispatch.h>
#include <ATen/ops/isneginf_meta_dispatch.h>
#include <ATen/ops/isposinf_meta_dispatch.h>
#include <ATen/ops/lcm_meta_dispatch.h>
#include <ATen/ops/le_meta_dispatch.h>
#include <ATen/ops/leaky_relu_meta_dispatch.h>
#include <ATen/ops/leaky_relu_backward_meta_dispatch.h>
#include <ATen/ops/lerp_meta_dispatch.h>
#include <ATen/ops/lgamma_meta_dispatch.h>
#include <ATen/ops/linalg_cholesky_ex_meta_dispatch.h>
#include <ATen/ops/linalg_cross_meta_dispatch.h>
#include <ATen/ops/linalg_inv_ex_meta_dispatch.h>
#include <ATen/ops/linalg_ldl_factor_ex_meta_dispatch.h>
#include <ATen/ops/linalg_ldl_solve_meta_dispatch.h>
#include <ATen/ops/linalg_lu_meta_dispatch.h>
#include <ATen/ops/linalg_lu_factor_ex_meta_dispatch.h>
#include <ATen/ops/linalg_lu_solve_meta_dispatch.h>
#include <ATen/ops/linalg_qr_meta_dispatch.h>
#include <ATen/ops/linalg_vector_norm_meta_dispatch.h>
#include <ATen/ops/linspace_meta_dispatch.h>
#include <ATen/ops/log_meta_dispatch.h>
#include <ATen/ops/log10_meta_dispatch.h>
#include <ATen/ops/log1p_meta_dispatch.h>
#include <ATen/ops/log2_meta_dispatch.h>
#include <ATen/ops/log_normal_meta_dispatch.h>
#include <ATen/ops/logaddexp_meta_dispatch.h>
#include <ATen/ops/logaddexp2_meta_dispatch.h>
#include <ATen/ops/logit_meta_dispatch.h>
#include <ATen/ops/logit_backward_meta_dispatch.h>
#include <ATen/ops/logspace_meta_dispatch.h>
#include <ATen/ops/lshift_meta_dispatch.h>
#include <ATen/ops/lt_meta_dispatch.h>
#include <ATen/ops/lu_unpack_meta_dispatch.h>
#include <ATen/ops/masked_fill_meta_dispatch.h>
#include <ATen/ops/masked_scatter_meta_dispatch.h>
#include <ATen/ops/max_meta_dispatch.h>
#include <ATen/ops/max_pool2d_with_indices_meta_dispatch.h>
#include <ATen/ops/max_pool2d_with_indices_backward_meta_dispatch.h>
#include <ATen/ops/maximum_meta_dispatch.h>
#include <ATen/ops/mean_meta_dispatch.h>
#include <ATen/ops/min_meta_dispatch.h>
#include <ATen/ops/minimum_meta_dispatch.h>
#include <ATen/ops/mish_meta_dispatch.h>
#include <ATen/ops/mm_meta_dispatch.h>
#include <ATen/ops/mse_loss_meta_dispatch.h>
#include <ATen/ops/mul_meta_dispatch.h>
#include <ATen/ops/ne_meta_dispatch.h>
#include <ATen/ops/neg_meta_dispatch.h>
#include <ATen/ops/nextafter_meta_dispatch.h>
#include <ATen/ops/nll_loss_backward_meta_dispatch.h>
#include <ATen/ops/nll_loss_forward_meta_dispatch.h>
#include <ATen/ops/norm_meta_dispatch.h>
#include <ATen/ops/normal_meta_dispatch.h>
#include <ATen/ops/polygamma_meta_dispatch.h>
#include <ATen/ops/pow_meta_dispatch.h>
#include <ATen/ops/prod_meta_dispatch.h>
#include <ATen/ops/put_meta_dispatch.h>
#include <ATen/ops/random_meta_dispatch.h>
#include <ATen/ops/range_meta_dispatch.h>
#include <ATen/ops/reciprocal_meta_dispatch.h>
#include <ATen/ops/reflection_pad1d_meta_dispatch.h>
#include <ATen/ops/reflection_pad1d_backward_meta_dispatch.h>
#include <ATen/ops/reflection_pad3d_meta_dispatch.h>
#include <ATen/ops/reflection_pad3d_backward_meta_dispatch.h>
#include <ATen/ops/relu_meta_dispatch.h>
#include <ATen/ops/remainder_meta_dispatch.h>
#include <ATen/ops/renorm_meta_dispatch.h>
#include <ATen/ops/replication_pad1d_meta_dispatch.h>
#include <ATen/ops/replication_pad1d_backward_meta_dispatch.h>
#include <ATen/ops/replication_pad2d_meta_dispatch.h>
#include <ATen/ops/replication_pad3d_meta_dispatch.h>
#include <ATen/ops/resize_meta_dispatch.h>
#include <ATen/ops/resize_as_sparse_meta_dispatch.h>
#include <ATen/ops/round_meta_dispatch.h>
#include <ATen/ops/rrelu_with_noise_meta_dispatch.h>
#include <ATen/ops/rshift_meta_dispatch.h>
#include <ATen/ops/rsqrt_meta_dispatch.h>
#include <ATen/ops/scatter_meta_dispatch.h>
#include <ATen/ops/scatter_add_meta_dispatch.h>
#include <ATen/ops/scatter_reduce_meta_dispatch.h>
#include <ATen/ops/set_meta_dispatch.h>
#include <ATen/ops/sgn_meta_dispatch.h>
#include <ATen/ops/sigmoid_meta_dispatch.h>
#include <ATen/ops/sigmoid_backward_meta_dispatch.h>
#include <ATen/ops/sign_meta_dispatch.h>
#include <ATen/ops/signbit_meta_dispatch.h>
#include <ATen/ops/silu_meta_dispatch.h>
#include <ATen/ops/silu_backward_meta_dispatch.h>
#include <ATen/ops/sin_meta_dispatch.h>
#include <ATen/ops/sinc_meta_dispatch.h>
#include <ATen/ops/sinh_meta_dispatch.h>
#include <ATen/ops/slow_conv_transpose2d_meta_dispatch.h>
#include <ATen/ops/smooth_l1_loss_meta_dispatch.h>
#include <ATen/ops/softplus_meta_dispatch.h>
#include <ATen/ops/softplus_backward_meta_dispatch.h>
#include <ATen/ops/softshrink_meta_dispatch.h>
#include <ATen/ops/softshrink_backward_meta_dispatch.h>
#include <ATen/ops/sort_meta_dispatch.h>
#include <ATen/ops/sparse_resize_meta_dispatch.h>
#include <ATen/ops/sparse_resize_and_clear_meta_dispatch.h>
#include <ATen/ops/special_airy_ai_meta_dispatch.h>
#include <ATen/ops/special_bessel_j0_meta_dispatch.h>
#include <ATen/ops/special_bessel_j1_meta_dispatch.h>
#include <ATen/ops/special_bessel_y0_meta_dispatch.h>
#include <ATen/ops/special_bessel_y1_meta_dispatch.h>
#include <ATen/ops/special_chebyshev_polynomial_t_meta_dispatch.h>
#include <ATen/ops/special_chebyshev_polynomial_u_meta_dispatch.h>
#include <ATen/ops/special_chebyshev_polynomial_v_meta_dispatch.h>
#include <ATen/ops/special_chebyshev_polynomial_w_meta_dispatch.h>
#include <ATen/ops/special_entr_meta_dispatch.h>
#include <ATen/ops/special_erfcx_meta_dispatch.h>
#include <ATen/ops/special_hermite_polynomial_h_meta_dispatch.h>
#include <ATen/ops/special_hermite_polynomial_he_meta_dispatch.h>
#include <ATen/ops/special_i0e_meta_dispatch.h>
#include <ATen/ops/special_i1_meta_dispatch.h>
#include <ATen/ops/special_i1e_meta_dispatch.h>
#include <ATen/ops/special_laguerre_polynomial_l_meta_dispatch.h>
#include <ATen/ops/special_legendre_polynomial_p_meta_dispatch.h>
#include <ATen/ops/special_log_ndtr_meta_dispatch.h>
#include <ATen/ops/special_modified_bessel_i0_meta_dispatch.h>
#include <ATen/ops/special_modified_bessel_i1_meta_dispatch.h>
#include <ATen/ops/special_modified_bessel_k0_meta_dispatch.h>
#include <ATen/ops/special_modified_bessel_k1_meta_dispatch.h>
#include <ATen/ops/special_ndtri_meta_dispatch.h>
#include <ATen/ops/special_scaled_modified_bessel_k0_meta_dispatch.h>
#include <ATen/ops/special_scaled_modified_bessel_k1_meta_dispatch.h>
#include <ATen/ops/special_shifted_chebyshev_polynomial_t_meta_dispatch.h>
#include <ATen/ops/special_shifted_chebyshev_polynomial_u_meta_dispatch.h>
#include <ATen/ops/special_shifted_chebyshev_polynomial_v_meta_dispatch.h>
#include <ATen/ops/special_shifted_chebyshev_polynomial_w_meta_dispatch.h>
#include <ATen/ops/special_spherical_bessel_j0_meta_dispatch.h>
#include <ATen/ops/special_xlog1py_meta_dispatch.h>
#include <ATen/ops/special_zeta_meta_dispatch.h>
#include <ATen/ops/sqrt_meta_dispatch.h>
#include <ATen/ops/sub_meta_dispatch.h>
#include <ATen/ops/sum_meta_dispatch.h>
#include <ATen/ops/tan_meta_dispatch.h>
#include <ATen/ops/tanh_meta_dispatch.h>
#include <ATen/ops/tanh_backward_meta_dispatch.h>
#include <ATen/ops/threshold_meta_dispatch.h>
#include <ATen/ops/threshold_backward_meta_dispatch.h>
#include <ATen/ops/topk_meta_dispatch.h>
#include <ATen/ops/triangular_solve_meta_dispatch.h>
#include <ATen/ops/tril_meta_dispatch.h>
#include <ATen/ops/triu_meta_dispatch.h>
#include <ATen/ops/trunc_meta_dispatch.h>
#include <ATen/ops/unfold_meta_dispatch.h>
#include <ATen/ops/uniform_meta_dispatch.h>
#include <ATen/ops/upsample_bicubic2d_meta_dispatch.h>
#include <ATen/ops/upsample_bicubic2d_backward_meta_dispatch.h>
#include <ATen/ops/upsample_bilinear2d_meta_dispatch.h>
#include <ATen/ops/upsample_bilinear2d_backward_meta_dispatch.h>
#include <ATen/ops/upsample_linear1d_meta_dispatch.h>
#include <ATen/ops/upsample_linear1d_backward_meta_dispatch.h>
#include <ATen/ops/upsample_nearest1d_meta_dispatch.h>
#include <ATen/ops/upsample_nearest1d_backward_meta_dispatch.h>
#include <ATen/ops/upsample_nearest2d_meta_dispatch.h>
#include <ATen/ops/upsample_nearest2d_backward_meta_dispatch.h>
#include <ATen/ops/upsample_nearest3d_meta_dispatch.h>
#include <ATen/ops/upsample_nearest3d_backward_meta_dispatch.h>
#include <ATen/ops/upsample_trilinear3d_meta_dispatch.h>
#include <ATen/ops/upsample_trilinear3d_backward_meta_dispatch.h>
#include <ATen/ops/view_meta_dispatch.h>
#include <ATen/ops/view_as_complex_meta_dispatch.h>
#include <ATen/ops/view_as_real_meta_dispatch.h>
#include <ATen/ops/xlogy_meta_dispatch.h>
#include <ATen/ops/zero_meta_dispatch.h>




#pragma once

#include <c10/core/SymFloatNodeImpl.h>
#include <c10/macros/Macros.h>
#include <c10/util/Exception.h>
#include <c10/util/intrusive_ptr.h>

#include <limits>
#include <memory>

namespace c10 {

// NB: this is actually double precision; we're using the Python naming here
class C10_API SymFloat {
 public:
  /*implicit*/ SymFloat(double d) : data_(d){};
  SymFloat(SymFloatNode ptr)
      : data_(std::numeric_limits<double>::quiet_NaN()), ptr_(std::move(ptr)){};
  SymFloat() : data_(0.0) {}

  SymFloatNodeImpl* toSymFloatNodeImplUnowned() const {
    return ptr_.get();
  }

  SymFloatNode toSymFloatNodeImpl() const;
  static c10::SymFloat toSymFloat(SymFloatNode sin);

  double expect_float() const {
    TORCH_CHECK(!is_symbolic());
    return data_;
  }

  // N.B. It's important to keep this definition in the header
  // as we expect if checks to be folded for mobile builds
  // where `is_symbolic` is always false
  C10_ALWAYS_INLINE bool is_symbolic() const {
    return ptr_;
  }

  int64_t as_float_unchecked() const {
    return data_;
  }

 private:
  // TODO: optimize to union
  double data_;
  SymFloatNode ptr_;
};

C10_API std::ostream& operator<<(std::ostream& os, SymFloat s);
} // namespace c10

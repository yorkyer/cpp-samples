#pragma once

#include <c10/macros/Macros.h>
#include <c10/util/Exception.h>
#include <c10/util/intrusive_ptr.h>
#include <memory>
#include <mutex>
#include <vector>

namespace c10 {

class SymFloat;
class SymFloatNodeImpl;
using SymFloatNode = c10::intrusive_ptr<SymFloatNodeImpl>;

class C10_API SymFloatNodeImpl : public c10::intrusive_ptr_target {
 public:
  c10::SymFloat toSymFloat();
  virtual ~SymFloatNodeImpl(){};

  template <typename T>
  c10::intrusive_ptr<T> dyn_cast() const {
    return c10::intrusive_ptr<T>::reclaim_copy(dynamic_cast<T*>(this));
  }

  virtual SymFloatNode wrap(double num) {
    TORCH_CHECK(false, "NYI");
  };
  virtual std::string str() {
    TORCH_CHECK(false, "NYI");
  };
  std::ostream& operator<<(std::ostream& os) {
    os << str();
    return os;
  };
};

} // namespace c10

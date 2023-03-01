#include <type_traits>
#include <iostream>

// template <class T>
// auto call_foo_imp(T t, int) -> decltype(std::declval<T>().foo(), void()) {
//     std::cout << "has foo\n";
//     t.foo();
// }

template <class T>
auto call_foo_imp(T t, int) -> decltype(&T::foo, void()) {
    std::cout << "has foo\n";
    t.foo();
}

template <class T>
auto call_foo_imp(T t, long) -> void {
    std::cout << "not foo\n";
}

template<class T>
auto call_foo(T t) -> decltype(call_foo_imp(t, 0), void()) {
    call_foo_imp(t, 0);
}

struct X { 
    virtual int y() { return 1; }
    int x() { std::cout << y() << std::endl; }
 };
struct Y : public X { 
   int y() override { return 2; }
};

int main(){
    Y y;
    X *x = &y;
    y.x();
    x->x();
}
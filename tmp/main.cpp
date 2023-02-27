#include <type_traits>
#include <iostream>

template <class T>
auto call_foo_imp(T t, int) -> decltype(std::declval<T>().foo(), void()) {
    std::cout << "has foo\n";
}

template <class T>
void call_foo_imp(T t, long) {
    std::cout << "not foo\n";
}

template<class T>
auto call_foo(T t) -> decltype(call_foo_imp(t, 0), void()) {
    call_foo_imp(t, 0);
}

struct X{ void foo(){} };
struct Y{};

int main(){
    X x;
    Y y;
    call_foo(x);
    call_foo(y);
}
#include <iostream>
#include <memory>

class Widget {
    int x{0};
public:
    Widget(int n) : x(n) {
        std::cout << "construct " << x << "\n";
    }
    Widget(const Widget &widget) {
        x = widget.x;
        std::cout << "copy construct from " << widget.x << "\n";
    }
    Widget(Widget &&widget) {
        x = widget.x;
        std::cout << "move construct from " << widget.x << "\n";
    }
    Widget& operator=(const Widget &widget) {
        x = widget.x;
        std::cout << "copy assignment from " << widget.x << "\n";
        return *this;
    }
    Widget& operator=(Widget &&widget) {
        x = widget.x;
        std::cout << "move assignment from " << widget.x << "\n";
        return *this;
    }
    ~Widget() {
        std::cout << "destruct " << x << "\n";
    }
};

Widget f(int n) {
    auto widget = Widget(n);
    return widget;
}

int main() {
    auto widget = f(3);
    return 0;
}
//how to create function in C++?

#include <iostream>
#include <algorithm>
#include <functional>

class Callbacks {
    static constexpr unsigned count = 1000;
    static Callbacks* instance;

    using CF = void(); // C-style callback type.
    using F = std::function<CF>; // C++ stateful callback type.

    F callbacks_[count];
    CF* c_style_callbacks_[count];

    template<unsigned Index>
    static void c_style_callback() {
        instance->callbacks_[Index]();
    }

    template<unsigned... Index>
    void make_c_style_callbacks(std::integer_sequence<unsigned, Index...>) {
        auto initializer_list = {(c_style_callbacks_[Index] = &c_style_callback<Index>)...};
        static_cast<void>(initializer_list);
    }

public:
    Callbacks() {
        make_c_style_callbacks(std::make_integer_sequence<unsigned, count>{});
        if(instance)
            throw; // One instance only please.
        instance = this;
    }

    Callbacks(Callbacks const&) = delete;
    Callbacks& operator=(Callbacks const&) = delete;

    ~Callbacks() noexcept {
        instance = 0;
    }

    CF* register_callback(F f) noexcept {
        // Linear search can be improved upon.
        auto condition = [](F const& f) { return !f; };
        auto index = std::find_if(std::begin(callbacks_), std::end(callbacks_), condition) - std::begin(callbacks_);
        if(index < count) {
            callbacks_[index] = std::move(f); // Assumes move-assignement is noexcept.
            return c_style_callbacks_[index];
        }
        return 0;
    }

    void unregister_callback(CF* cf) noexcept {
        // Linear search can be improved upon.
        auto index = std::find(std::begin(c_style_callbacks_), std::end(c_style_callbacks_), cf) - std::begin(c_style_callbacks_);
        if(index < count)
            callbacks_[index] = {};
        else
            throw; // cf has not been found. Programming error.
    }
};

Callbacks* Callbacks::instance = 0;

int main() {
    Callbacks c;
    unsigned n = 0;

    auto p0 = c.register_callback([m = n++]() { std::cout << m << '\n'; });
    auto p1 = c.register_callback([m = n++]() { std::cout << m << '\n'; });
    auto p2 = c.register_callback([m = n++]() { std::cout << m << '\n'; });

    p0(); // Outputs 0.
    p1(); // Outputs 1.
    p2(); // Outputs 2.

    c.unregister_callback(p2);
    c.unregister_callback(p1);
    c.unregister_callback(p0);
}






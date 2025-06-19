#include <iostream>
#include <assert.h>

// Implementation of multiplication without using the multiplication operator
template <typename T>
constexpr T multiply_it(T a, T b)
{
    static_assert(std::is_integral<T>::value, "multiply_it requires integral types");
    T running_total = 0;
    unsigned int addition_count = 0;
    while (static_cast<int>(addition_count) < b)
    {
        running_total += a;
        addition_count += 1;
    }

    return running_total;
};

template <typename T>
constexpr T multiply_recursive(T a, T b, T result = 0)
{
    static_assert(std::is_integral<T>::value, "multiply_it requires integral types");
    if (b == 0)
    {
        return result;
    }
    return multiply_recursive(a, b - 1, result + a);
};

int main()
{

    std::cout << "Enter two integers to multiply: ";
    int a, b;
    if (!(std::cin >> a >> b))
    {
        std::cerr << "Invalid input. Please enter two integers.\n";
        return 1;
    }
    int result_i = multiply_it(a, b);
    int result_recursive = multiply_recursive(a, b);
    assert(result_i == result_recursive);
    assert(result_i == a * b);

    std::cout << a << " * " << b << " = " << result_i << "\n";
}

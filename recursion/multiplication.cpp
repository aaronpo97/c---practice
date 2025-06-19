#include <iostream>
#include <assert.h>

/**
 * Multiplication algorithm using repeated additions.
 *
 * \param a A number of any integral type.
 * \param b A number of the same type as a.
 *
 * \returns The result of the multiplication
 *
 * \example
 * \code
 * int result = multiply_it(3, 4); // result will be 12
 * \endcode
 */
template <typename T>
constexpr T multiply_it(T a, T b)
{

    // Check if T is an integral type. If not, this will cause a compile error
    static_assert(std::is_integral<T>::value, "multiply_it requires integral types");

    // Multiplication is just repeated addition b times

    // Keep track of a running total
    T running_total = 0;

    // Create a counter to keep track of how many additions have been performed
    size_t addition_count = 0;
    while (static_cast<T>(addition_count) < b)
    {
        running_total += a;
        addition_count += 1;
    }

    return running_total;
};

/**
 * Recursive multiplication algorithm using repeated additions.
 *
 * \param a A number of any integral type.
 * \param b A number of the same type as a.
 * \param result The accumulated result, default is 0.
 *
 * \returns The result of the multiplication
 *
 * \example
 * \code
 * int result = multiply_recursive(3, 4); // result will be 12
 * \endcode
 */
template <typename T>
constexpr T multiply_recursive(T a, T b, T result = 0)
{
    // Check if T is an integral type. If not, this will cause a compile error
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

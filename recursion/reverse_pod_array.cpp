#include <assert.h>
#include <string.h>
#include <utility>
#include <algorithm>
#include <iostream>

template <typename T>
void reverse_c_array_iteration(T arr[], size_t length)
{
    for (size_t i = 0; i < length / 2; i++)
    {
        std::swap(arr[i], arr[length - i - 1]);
    }
}

template <typename T>
void reverse_c_array_recursion(T arr[], const size_t length, const size_t i = 0)
{
    if (i >= length / 2)
    {
        return;
    }

    std::swap(arr[i], arr[length - i - 1]);
    reverse_c_array_recursion(arr, length, i + 1);
}

int main()
{
    char message[] = "Hello, World!";
    char message2[] = "Hello!";

    reverse_c_array_iteration(message, strlen(message));
    reverse_c_array_recursion(message2, strlen(message2));

    std::cout << message2 << "\n";

    std::cout << "Recursive reverse: " << message2 << std::endl;

    return 0;
}
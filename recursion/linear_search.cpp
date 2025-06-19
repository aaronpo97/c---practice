#include <vector>
#include <iostream>

/**
 * Linear search algorithm using iteration.
 *
 * \param v The vector to search.
 * \param item The item to search for.
 *
 * \returns The index of the item if found, otherwise -1.
 *
 * \example
 * \code
 * std::vector<int> numbers = {1, 2, 3, 4, 5};
 * int indexA = linear_search_iteration(numbers, 3); // index will be 2
 * int indexB = linear_search_iteration(numbers, 6); // index will be -1
 * \endcode
 */
template <typename T>
constexpr int linear_search_iteration(const std::vector<T> &v, const T &item)
{
    int index = -1;
    for (size_t i = 0; i < v.size(); i += 1)
    {
        if (v.at(i) == item)
        {
            index = i;
            break;
        }
    }

    return index;
}

/**
 * Linear search algorithm using recursion.
 */
template <typename T>
int linear_search_recursion(const std::vector<T> &v, const T &item, int i = 0)
{
    if (i >= v.size())
    {
        return -1;
    }
    if (v.at(i) == item)
    {
        return i;
    }

    return linear_search_recursion(v, item, i + 1);
}

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int indexA = linear_search_iteration(numbers, 3); // index will be 2
    int indexB = linear_search_iteration(numbers, 6); // index will be -1

    // Output the results
    std::cout << "Index of 3: " << indexA << std::endl;
    std::cout << "Index of 6: " << indexB << std::endl;

    int indexC = linear_search_recursion(numbers, 3); // index will be 2
    int indexD = linear_search_recursion(numbers, 6); // index will be -1
    // Output the results
    std::cout << "Recursive index of 3: " << indexC << std::endl;
    std::cout << "Recursive index of 6: " << indexD << std::endl;

    return 0;
}

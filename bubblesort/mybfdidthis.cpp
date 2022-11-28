#include <iostream>
#include <chrono>
using namespace std::chrono;

int main()
{
    auto start = high_resolution_clock::now();
    int array[]{5, 3, 7, 6, 56, 8, 4, 9, 7, 15, 3, 1, 29, 44};

    int carry;
    bool sort;
    for (int i = 1; i < sizeof(array) / sizeof(int); i++)
    {
        sort = true;
        for (int j = i; j < sizeof(array) / sizeof(int); j++)
        {
            if (array[i - 1] > array[j])
            {
                carry = array[i - 1];
                array[i - 1] = array[j];
                array[j] = carry;
                sort = false;
            }
        }
        if (sort)
            break;
    }
    std::cout << std::endl
              << "{ ";
    for (int j = 0; j < sizeof(array) / sizeof(int); j++)
        std::cout << array[j] << " ";
    std::cout << "}";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // To get the value of duration use the count()
    // member function on the duration object
    std::cout << duration.count() << std::endl;

    return 0;
}
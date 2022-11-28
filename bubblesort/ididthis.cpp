#include <iostream>
#include <chrono>
using namespace std::chrono;

void sort(int array[], int size);

int main(int argc, char const *argv[])
{
    auto start = high_resolution_clock::now();
    int array[]{5, 3, 7, 6, 56, 8, 4, 9, 7,15,3,1,29,44};
    sort(array, sizeof(array) / sizeof(int));
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // To get the value of duration use the count()
    // member function on the duration object
    std::cout << duration.count() << std::endl;
    return 0;
}

void sort(int array[], int size)
{
    bool sorted = true;
    int carry{0};
    std::cout << sizeof(int) << std::endl;
    std::cout << "<------------------->" << std::endl;

    for (size_t i = 0; i < size; i++)
    {
        sorted = true;
        for (size_t j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                carry = array[j];
                array[j] = array[j + 1];
                array[j + 1] = carry;
                sorted = false;
            }
        }
        if (sorted)
        {
            break;
        }

        std::cout << "[ ";
        for (size_t j = 0; j < size; j++)
        {
            std::cout << array[j] << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "<------------------->" << std::endl;
}

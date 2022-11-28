#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;


void swap(int *a, int *b);
void quicksort(int array[], int size, int high, int low);
void print(int array[], int size);

int main(int argc, char const *argv[]){
    int array[]{5, 3, 7, 6, 56, 8, 4, 9, 7,15,3,1,29,44};
    int size = sizeof(array) / sizeof(int);

    std::cout << "Sorting: " << std::endl;
    print(array, size);
    std::cout << "\t ---> " << std::endl;

    auto start = high_resolution_clock::now();

    quicksort(array, size, 0, size - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    print(array, size);
    std::cout << "Duration (ms): " << duration.count() << std::endl;
    return 0;
}
void quicksort(int array[], int size, int low, int high){
    int pivot = high;
    int smallest = low - 1;
    // partition array
    if (low < high){
        for (size_t i = low; i < high; i++){
            if (array[i] < array[pivot]){
                swap(&array[i], &array[smallest + 1]);
                smallest++;
            }
            
        }
        swap(&array[pivot],&array[smallest+1]);

        pivot = smallest + 1;
        quicksort(array,size,low,pivot-1);
        quicksort(array,size,pivot+1,high);
    }
}

void print(int array[], int size){
    std::cout << "[ ";
    for (size_t i = 0; i < size - 1; i++){
        std::cout << array[i] << ", ";
    }
    std::cout << array[size - 1] << " ]" << "\n";
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
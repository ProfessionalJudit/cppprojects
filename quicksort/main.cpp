#include <iostream>
#include <vector>

void swap(int *a, int *b);
void quicksort(int array[], int size, int high, int low);
void print(int array[], int size);

int main(int argc, char const *argv[]){
    int array[]{5, 3, 7, 6, 8, 4, 9, 7,15,3,1,29,44,56};
    
    int size = sizeof(array) / sizeof(int);

    print(array, size);
    quicksort(array, size, 0, size - 1);

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
        print(array, size);

        pivot = smallest + 1;
        std::cout << low << " " << high  << std::endl;
        quicksort(array,size,low,pivot-1);
        quicksort(array,size,pivot+1,high);
    }
}

void print(int array[], int size){
    std::cout << "Sorting: " << std::endl;
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
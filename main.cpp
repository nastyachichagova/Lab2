#include <iostream>

template <typename T>
void bubble_sort(T arr[], int size_arr){
    while (size_arr--){
        bool swapped = false;

        for(int i = 0; i < size_arr; i++){
            if (arr[i] > arr[i+1]){
                std::swap (arr[i], arr[i+1]);
                swapped = true;
            }
        }

        if (!swapped){
            break;
        }
    }
}

int count_sort(int arr[], int size_array){
    int k = arr[0];

    for (int i = 0; i < size_array; i++){
        k = std::max(k, arr[i]);
    }

    int count[10]={0};

    for (int i = 0; i < size_array; i++){
        count[arr[i]]++;
    }

    for (int i = 1; i <=k; i++){
        count[i] += count[i-1];
    }

    int output[size_array];
    for (int i = size_array -1; i >= 0; i--){
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < size_array; i++){
        arr[i] = output[i];
    }
}

template <typename T>
T get_pivot_idx(T arr[], int idx_start, int idx_end){
    int pivot = idx_start - 1;

    for (int k = idx_start; k <= idx_end ; k++){
        if (arr[k] < arr[idx_end]){
            pivot++;
            std::swap(arr[pivot], arr[k]);
        };
    }

    pivot++;

    std::swap (arr[pivot], arr[idx_end]);

    return pivot;
}

template <typename T>
void quick_sort(T arr[], int idx_start, int idx_end){
    if (idx_start >= idx_end){
        return;
    }

    int idx_pivot = get_pivot_idx(arr, idx_start, idx_end);

    quick_sort(arr, idx_start, idx_pivot-1);
    quick_sort(arr, idx_pivot+1, idx_end);
}

template <typename T>
void print_array(T arr[], int size_arr){
    for (int i = 0; i < size_arr; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}


int main() {
    int arr_of_int[] = {1, 3, 2,0, 1, -1};
    int size_arr_int = sizeof(arr_of_int)/sizeof(arr_of_int[0]);

    double arr_of_double[] = {1.5, 3.2, -2,0.5};
    int size_arr_double = sizeof(arr_of_double)/sizeof(arr_of_double[0]);

    std::cout << "Исходный массив" << std::endl;
    print_array(arr_of_int, size_arr_int);

    quick_sort(arr_of_int, 0, 5);

    std::cout << "Сортированный массив" << std::endl;
    print_array(arr_of_int, size_arr_int);

    std::cout << "Исходный массив" << std::endl;
    print_array(arr_of_double, size_arr_double);

    bubble_sort(arr_of_double, 4);

    std::cout << "Сортированный массив" << std::endl;
    print_array(arr_of_double, size_arr_double);

    return 0;
}

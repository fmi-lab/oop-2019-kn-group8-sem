#include <iostream>

int *map(int *array, int array_size, int (*fn)(int)) {
    int *result = new int[array_size];
    for (int i = 0; i < array_size; ++i) {
        result[i] = fn(array[i]);
    }
    return result;
}

int square(int x) {
    return x * x;
}
int cube(int x) {
    return x * x * x;
}

void print_array(int *array, int array_size) {
    for (int i = 0; i < array_size; ++i) {
        std::cout << array[i] << ", ";
    }
    std::cout << "\n";
}

int main() {
    int input_array[3] = {1, 2, 3};
    int size = sizeof(input_array) / sizeof(input_array[0]);
    int *result = map(input_array, size, square);
    print_array(result, size);
    delete result;
    result = map(input_array, size, cube);
    print_array(result, size);
    delete result;

    return 0;
}
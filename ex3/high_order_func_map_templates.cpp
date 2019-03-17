#include <iostream>

template <typename T>
T *map(T *array, int array_size, T (*fn)(T)) {
    T *result = new T[array_size];
    for (int i = 0; i < array_size; ++i) {
        result[i] = fn(array[i]);
    }
    return result;
}

template <typename T>
T square(T x) {
    return x * x;
}

char upper(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        return 'A' + letter - 'a';
    }
    return letter;
}

template <typename T>
void print_array(T *array, int array_size) {
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


    char s[10] = "abc";
    std::cout << map(s, strlen(s), upper) << std::endl;

    return 0;
}
// gets lots of ints, puts them in a dynamically allocated array, and 

#include <iostream>

int main() {
    int input;
    int container_size = 7;
    int* array = new int[container_size];
    int array_size = 0;
    int sum = 0;
    std::cout << "input numbers:" << std::endl;
    while (std::cin >> input) {
        array[array_size++] = input;
        if (array_size >= container_size) {
            // resize array
            int* new_array = new int[container_size * 2];
            std::copy(array, array + container_size, new_array);
            container_size *= 2;
            delete[] array;
            array = new_array;
        }
    }
    
    // print array
    std::cout << "array: { ";
    for (int i = 0; i < array_size; ++i) {
        std::cout << array[i] << ", ";
        sum += array[i];
    }
    std::cout << "}" << std::endl;
    
    std::cout << "sum: " << sum << std::endl;
    
    delete[] array;

    return 0;
}

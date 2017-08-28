#include <iostream>
#include <cstring>


int getByte(long long var, int number) {
    return (int) ((var >> (number * 8)) & 255);
}

void radixSort(long long* array, size_t n) {
    int* keyArray = new int[256]{0};
    long long* tmpArray = new long long[n];
    for (int byteNumber = 0; byteNumber < 8; byteNumber++) {
        for (int i = 0; i < 256; i++)
            keyArray[i] = 0;

        for (int i = 0; i < n; i++)
            keyArray[getByte(array[i], byteNumber)]++;

        int lastVar = 0;
        for (int i = 0; i < 256; i++) {
            int tmp = keyArray[i];
            keyArray[i] = lastVar;
            lastVar += tmp;
        }

        for (int i = 0; i < n; i++) {
            int byte = getByte(array[i], byteNumber);
            tmpArray[keyArray[byte]] = array[i];
            keyArray[byte]++;
        }

        for (int i = 0; i < n; i++)
            array[i] = tmpArray[i];
    }
    delete[] tmpArray;
    delete[] keyArray;
}

int main() {
    size_t n = 0;
    std::cin >> n;

    long long *array = new long long[n];
    for (int i = 0; i < n; i++)
        std::cin >> array[i];

    radixSort(array, n);

    for (int i = 0; i < n; i++)
        std::cout << array[i] << ' ';

    delete[] array;
    return 0;
} 

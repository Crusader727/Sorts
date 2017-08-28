#include <iostream>

int binarySearch(int* a, int n, int x) {
    if ((n == 0) || (x < a[0]) || (x > a[n - 1]))
        return -1;
    int first = 0;
    int last = n;
    while (first < last) {
        int mid = first + (last - first) / 2;
        if (x <= a[mid])
            last = mid;
        else
            first = mid + 1;
    }
    if (a[last] == x)
        return last;
    else
        return -1;
} 

int main () {
    int a[] = {0, 1, 3, 4, 5, 6, 7, 8, 9};
    int x, l;
    l = 9;
    std::cin >> x;
    std::cout << binarySearch(a, l, x);
    return 0;
}

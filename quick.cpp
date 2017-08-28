#include <iostream>

int a[100];

void quickSort(int l, int r) 
{
    int x = a[(l + r) /2];
    int i = l;
    int j = r;
    while(i <= j) {
        while(a[i] < x) 
            i++;
        while(a[j] > x) 
            j--;
        if(i <= j) {
            std::swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (i<r)
        quickSort(i, r);
    
    if (l<j)    
        quickSort(l, j);    
}
int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin>>a[i];
    }
    quickSort(0, n-1);
    for(int i = 0; i < n; i++) {
        std::cout<<a[i]<<" ";
    }        
    return 0;
}

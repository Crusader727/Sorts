 #include<iostream>


 void heapify(int* a, int i, int n) {
	int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
	if((left < n) && (a[left] > a[largest])) {
		largest = left;
	}
	if((right < n) && (a[right] > a[largest])) {
		largest = right;
	}
	if(largest != i){
		std::swap(a[i], a[largest]);
		heapify(a, largest, n);
	}
}

void buildHeap(int* a, int n){
	for(int i = n / 2 -1; i >= 0; i--) {
		heapify(a, i, n);
	}
}

void heapSort(int* a, int n) {
	buildHeap(a, n);
	for(int i = n - 1; i >= 1; i--) {
		std::swap(a[0], a[i]);
		heapify(a, 0, i);
	}
}

int main() {
    int n;//количество элементов в массиве
    std::cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++) {
        std::cin>>a[i];
    }
    heapSort(a, n);
    for(int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }   
    delete[] a;     
    return 0;
}

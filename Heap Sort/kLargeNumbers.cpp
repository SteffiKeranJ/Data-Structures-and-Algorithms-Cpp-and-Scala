#include <iostream>

using namespace std;

void heapify(int i, int arr[], int n) {
    if(i >= n/2) return;
    int left = 2*i+ 1;
    int right = 2*i+2;
    int smallest = i;
    if(left < n && arr[left] < arr[i]) {
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if(smallest!=i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(smallest, arr, n);
    }
    
}


void buildheap(int arr[], int k) {
    for(int i = k/2-1; i >= 0; --i) {
        heapify(i, arr, k);
    }
}

void minHeap(int arr[], int k, int n) {
    buildheap(arr, k);
    for(int i = k; i < n-1; ++i) {
        if(arr[0] > arr[i]) continue;
        else {
            arr[0] = arr[i];
            heapify(0, arr, k);
        }
    }
}

int main()
{
    int arr[] = { 1, 5,3, 8, 9, 7, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    
    cout << "Input K: ";
    cin >> k;
    minHeap(arr, k, n);
    cout << "The k large elements in this array are ";
    for(int i = 0; i < k; ++i) {
        cout << arr[i] << endl;
    }
    return 0;
}

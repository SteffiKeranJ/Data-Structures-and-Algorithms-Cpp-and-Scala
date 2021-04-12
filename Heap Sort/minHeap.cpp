#include "pch.h"
#include <iostream>
using namespace std;
void heapify(int arr[], int i, int n) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int smallest = i;
	if (left < n && arr[left] < arr[smallest]) {
		smallest = left;
	}
	if (right < n && arr[right] < arr[smallest]) {
		smallest = right;
	}

	if (smallest != i) {
		int temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;
		heapify(arr, smallest, n);
	}
}

void buildMaxHeap(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {
		heapify(arr, i, n);
	}
}

void heapSort(int arr[], int n) {
	buildMaxHeap(arr, n);
	for (int i = n-1; i >=0; --i) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, 0, i);
	}
}


/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}

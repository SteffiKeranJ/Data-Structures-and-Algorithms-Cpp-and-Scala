// heapsort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int H[50];
int n = -1;
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

/* Find the parent for a given index*/
int findParent(int idx) {
	return (idx - 1) / 2;
}

/* Find left child's index for given index */
int findLeft(int idx) {
	return (2 * idx) + 1;
}

/* Find right child's index for given index */
int findRight(int idx) {
	return (2 * idx) + 2;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void shiftUp(int idx) {
	while (idx > 0 && H[findParent(idx)] < H[idx]) {
		swap(&H[findParent(idx)], &H[idx]);
		idx = findParent(idx);
	}
}

void shiftDown(int idx) {
	int maxim = idx;
	int left = findLeft(idx);

	if (left <= n && H[left] > H[maxim]) {
		maxim = left;
	}
	int right = findRight(idx);
	if (right <= n && H[right] > H[maxim]) {
		maxim = right;
	}

	if (maxim != idx) {
		swap(&H[maxim], &H[idx]);
		shiftDown(maxim);
	}
}

void insert(int i) {
	n += 1;
	H[n] = i;
	shiftUp(n);
}

int getMax() {
	return H[0];
}

void extractMax() {
	H[0] = H[n];
	// shrink the size
	n -= 1;
	// shift down
	shiftDown(0);
}

// Driver code
int main()
{
	
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arrN = sizeof(arr) / sizeof(arr[0]);
	
	// insert into heap
	for (int i = 0; i < arrN; ++i) {
		insert(arr[i]);
	}

	cout << "1. Priority Queue is \n";
	printArray(H, n + 1);
	cout << endl;

	cout << "2. Node with Maximum priority is: "<< getMax() <<endl;
	extractMax();
	cout << "3. Priority Queue after extracting the maximum: " << endl;
	
	printArray(H, n + 1);
	cout << endl;

}

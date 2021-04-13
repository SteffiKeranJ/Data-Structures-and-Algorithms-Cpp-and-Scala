// heapsort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(int arr[], int n) {
	int j, key;
	for (int i = 1; i < n; ++i) {
		j = i;
		key = arr[i];
		while (j > 0 && arr[j] < arr[j - 1]) {
			swap(&arr[j], &arr[j - 1]);
			j--;
		}
	}
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arrN = sizeof(arr) / sizeof(arr[0]);
	
	cout << "Original Array is: \n";
	printArray(arr, arrN);
	insertionSort(arr, arrN);
	cout << "Array after Insertion sort is: \n";
	printArray(arr, arrN);
}

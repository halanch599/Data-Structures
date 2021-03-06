// SortingApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

// C program for insertion sort 
#include <stdio.h> 
#include <math.h> 
using namespace std;
//void bubbleSort(int arr[], int n)
//{
//	int i, j;
//	for (i = 0; i < n - 1; i++)
//		for (j = 0; j < n - i - 1; j++)
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//}
//void insertionSort(int arr[], int n)
//{
//	int element,j;
//	for (int i = 1; i < n; i++)
//	{
//		element = arr[i];
//		j = i - 1;
//		while (j >= 0 && arr[j] > element)
//		{
//			arr[j + 1] = arr[j];
//			j = j - 1;
//		}
//		arr[j + 1] = element;
//	}
//}
//void selectionSort(int arr[], int n)
//{
//	int min;
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		min = i;
//		for (int j = i + 1; j < n; j++)
//			if (arr[j] < arr[min])
//				min= j;
//		int temp = arr[i];
//		arr[i] = arr[min];
//		arr[min] = temp;
//	}
//}
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
}

//int partition(int arr[], int low, int high)
//{
//	int pivot = arr[high];    // pivot 
//	int i = (low - 1);  // Index of smaller element 
//
//	for (int j = low; j <= high - 1; j++)
//	{
//		// If current element is smaller than or 
//		// equal to pivot 
//		if (arr[j] <= pivot)
//		{
//			i++;    
//			int temp = arr[i ];
//			arr[i] = arr[j];
//			arr[j] = temp;
//		}
//	}
//	int temp = arr[i + 1];
//	arr[i + 1] = arr[high];
//	arr[high] = temp;
//
//	return (i + 1);
//}

//int partition(int *a, int m, int n)
//{
//	int j=m, pivot;
//	pivot = a[n];
//	for (int i = m; i < n; i++)
//	{
//		if (a[i] <= pivot)
//		{
//			swap(a[j], a[i]);
//			j++;
//		}
//	}
//	swap(a[j], a[n]);
//	return j;
//}
//
//int partition(int *a, int left, int right)
//{
//	int j = left, pivot;
//	int m = (left + right) / 2;
//	pivot = a[m];
//	for (int i = left; i < right; i++)
//	{
//		if (a[i] <= pivot)
//		{
//			swap(a[j], a[i]);
//			j++;
//		}
//	}
//	swap(a[j], a[m]);
//	return j;
//}

//int pivot(int a[], int first, int last)
//{
//	int  p = first;
//	int pivotElement = a[first];
//
//	for (int i = first + 1; i <= last; i++)
//	{
//		if (a[i] <= pivotElement)
//		{
//			p++;
//			swap(a[i], a[p]);
//		}
//	}
//
//	swap(a[p], a[first]);
//
//	return p;
//}

//
//int partition(int arr[], int left, int right)
//{
//	int i = left;
//	int j = right;
//	int pivot = arr[left + (right - left) / 2]; // set pivot to value
//
//	if (left >= right)
//	{
//		while (i <= j)
//		{
//			while (arr[i] > pivot)i++;   // use pivot by value
//			while (arr[j] < pivot)j--;  // use pivot by value
//			if (i <= j)
//			{
//				swap(arr[i], arr[j]);
//				i++;
//				j--;
//			}
//		}
//	}
//	return i;
//	//if (left < j)quickSortMiddle(a, left, j); // < not <=
//	//if (i < right)quickSortMiddle(a, i, right); // < not <=
//}
//
//void quickSort(int arr[], int left, int right)
//{
//	if (left < right)
//	{
//
//		int pi = partition(arr, left, right);
//
//		quickSort(arr, left, pi - 1);
//		quickSort(arr, pi + 1, right);
//	}
//}
//// Reference : https://www.geeksforgeeks.org/merge-sort/
//void merge(int arr[], int l, int m, int r)
//{
//	int i = 0, j = 0, k = 1;
//	int n1 = m - l + 1;
//	int n2 = r - m;
//	
//	// L and R temp arrays
//	vector<int> L(n1);
//	vector<int> R(n2);
//	
//	// Copy data from orignal array to L
//	for (i = 0; i < n1; i++)
//		L[i] = arr[l + i];
//	
//	// Copy data from orignal array to R
//	for (j = 0; j < n2; j++)
//		R[j] = arr[m + 1 + j];
//	
//	// copy elements from  L or R into arr in sorted order
//	while (i < n1 && j < n2) 
//	{
//		if (L[i] <= R[j])
//		{
//			arr[k] = L[i];
//			i++;
//		}
//		else
//		{
//			arr[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//
//	// Copy the remaining elements L into arr of there are any
//	while (i < n1)
//	{
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//
//	// Copy the remaining elements R into arr of there are any
//	while (j < n2)
//	{
//		arr[k] = R[j];
//		j++;
//		k++;
//	}
//}
//void mergeSort(int arr[], int l, int r)
//{
//	if (l < r)
//	{
//		//find the mid point
//		int m = l + (r - l) / 2;
//		// call mergesor on L (Left arrary)
//		mergeSort(arr, l, m);
//		// call mergesor on R (Right arrary)
//		mergeSort(arr, m + 1, r);
//		// Merge R and L in sorting order
//		merge(arr, l, m, r);
//	}
//}

void quickSort(int *arr, int left, int right)
{
	if (left >= right)return;
	//int pivot = arr[(right +left) / 2];
	int pivot = arr[right ];
	int temp, i = left, j = right ;
	while (i <= j)
	{
		while (arr[i] < pivot)i++;//search from left
		while (arr[j] > pivot)j--;// search from right
		
		if (i >= j)
			break;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	quickSort(arr, left, j);
	quickSort(arr, j + 1, right);
}


int main()
{

	int arr[] = { 5,9,7,3,8,2 };
	int n = 6;

	printArray(arr, n);
	cout << endl;
	//mergeSort(arr, 0, n - 1);
	//printArray(arr, n);
	//cout << endl;

	quickSort(arr, 0, n - 1);
	printArray(arr, n);

	//insertionSort(arr, n);
	//printArray(arr, n);
	/*selectionSort(arr, n);
	printArray(arr, n); */

	/*bubbleSort(arr, n);
	printArray(arr, n);
*/
	getchar();
}

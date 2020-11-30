#pragma once

int isBigger(int a, int b);

int isSmaller(int a, int b);

int isSmaller_check(int a, int b);

int check(int* a, int n);

void SelectionSort(int* a, int n);

void InsertionSort(int* a, int n);

void BubbleSort(int* a, int n);

void MergeSort(int* a, int n);

void MergeSort_recur(int* a, int l, int r, int* temp);

void Merge(int* a, int l, int r, int m, int* temp);

void QuickSort(int* a, int n);

void QuickSort_recur(int* a, int l, int r);

void HeapSort(int* a, int n);

void Heapify(int* a, int n, int i);

void createHeap(int* a, int n);

int checkHeap(int* a, int n);

void binaryInsertionSort(int* a, int n);

int recursiveBinarySearch(int* a, int left, int right, int key);

void binaryInsertionSort_search(int* a, int n, int x);


void _sort(int order, int size, void(alg)(int*, int));


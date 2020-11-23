#pragma once

int isBigger(int a, int b);

int isSmaller(int a, int b);

void SelectionSort(int* a, int n, int(cmpr)(int, int));

void InsertionSort(int* a, int n, int(cmpr)(int, int));

void BubbleSort(int* a, int n, int(cmpr)(int, int));

void MergeSort(int* a, int n, int(cmpr)(int, int));

void MergeSort_recur(int* a, int l, int r, int* temp, int(cmpr)(int, int));

void Merge(int* a, int l, int r, int m, int* temp, int(cmpr)(int, int));

void QuickSort(int* a, int n, int(cmpr)(int, int));

void QuickSort_recur(int* a, int l, int r, int(cmpr)(int, int));

void _sort(int order, int size, void(alg)(int*, int, int(int, int)));

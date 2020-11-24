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

void _sort(int order, int size, void(alg)(int*, int));


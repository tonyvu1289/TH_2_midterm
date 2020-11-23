#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include "DataGenerator.h"
#include "SortAlgorithm.h"
using namespace std;
int isBigger(int a, int b)
{
	return a > b;
}
int isSmaller(int a, int b)
{
	return a < b;
}
int isSmaller_check(int a, int b)
{
	return a <= b;
}
int check(int* a, int n, int(cmpr)(int, int))
{
	for (int i = 0; i < n-1; i++)
	{
		if (!cmpr(a[i], a[i + 1]))
			return 0;
	}
	return 1;
}
void SelectionSort(int* a, int n, int(cmpr)(int, int))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cmpr(a[j], a[i]))
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}
void InsertionSort(int* a, int n, int(cmpr)(int, int))
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j >0; j--)
		{
			if (cmpr(a[j], a[j - 1]))
				HoanVi(a[j], a[j - 1]);
		}
	}
}
void BubbleSort(int* a, int n, int (cmpr)(int, int))
{
	for (int i = n-1; i >1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (cmpr(a[j + 1], a[j]))
				HoanVi(a[j + 1], a[j]);
		}
	}
}
void MergeSort(int *a, int n, int (cmpr)(int, int))
{
	int* temp = new int[n];
	MergeSort_recur(a, 0, n - 1, temp,cmpr);
	delete[]temp;
}
void MergeSort_recur(int *a, int l, int r, int* temp, int (cmpr)(int, int))
{
	if (!(l < r))
		return;
	int mid = (l + r) / 2;
	MergeSort_recur(a, l, mid, temp,cmpr);
	MergeSort_recur(a, mid + 1, r, temp,cmpr);
	Merge(a, l, r, mid, temp, cmpr);
}
void Merge(int* a, int l, int r, int m, int* temp, int (cmpr)(int, int))
{
	int i = l, j = m+1;
	int k=l;
	for (int index = l; index < r+1; index++)
	{
		temp[index] = a[index];
	}
	while (i <= m && j <= r)
	{
		if (cmpr(temp[i], temp[j]))
		{
			a[k] = temp[i];
			i++;
		}
		else
		{
			a[k] = temp[j];
			j++;
		}
		k++;
	}
	while (i<=m)
	{
		a[k] = temp[i];
		i++;
		k++;
	}
	while (j <= r)
	{
		a[k] = temp[j];
		j++;
		k++;
	}
}
void QuickSort(int* a, int n, int (cmpr)(int, int))
{
	QuickSort_recur(a, 0, n - 1, cmpr);
}
void QuickSort_recur(int* a, int l, int r, int (cmpr)(int, int))
{
	if (l >= r||l<0||right <0)
		return;
	int i = l, j = r;
	int x = a[(l + r) / 2];
	while (i<j)
	{
		while (cmpr(a[i], x)) i++;
		while (cmpr(x, a[j])) j--;
		if (i <= j)
		{
			HoanVi(a[i++], a[j--]);
		}
	}
	QuickSort_recur(a, l, j, cmpr);
	QuickSort_recur(a, i, r, cmpr);
}

void _sort(int order,int size,void(alg)(int*, int, int (int, int)))
{
	int* a = new int[size];
	GenerateData(a, size, order);
	alg(a, size, isSmaller);
	cout << "\t\tdone! checking...";
	cout<<check(a, size, isSmaller_check)<<endl;
	delete[] a;
}

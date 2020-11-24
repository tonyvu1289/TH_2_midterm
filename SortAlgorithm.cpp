#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include "DataGenerator.h"
#include "SortAlgorithm.h"
using namespace std;
extern ofstream out;
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
int check(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		if (a[i]>a[i+1])
			return 0;
	}
	return 1;
}
void SelectionSort(int* a, int n)
{
	int imin;
	
	for (int i = 0; i < n - 1 ; i++)
	{
		imin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[imin])
				imin = j;
		}
		HoanVi(a[imin], a[i]);
	}
}
void InsertionSort(int* a, int n)
{
	int flag = 1;
	int j;
	int* sentinel = (a - 1);
	sentinel = new int;
	*sentinel = INT_MIN;
	for (int i = 1; i < n; i++)
	{
		flag = 0;
		j = i;
			while (*(a+j) < *(a+j - 1))
			{
				HoanVi(a[j], a[j - 1]);
				flag = 1;
				j--;
			}
		}
	delete sentinel;
}
void BubbleSort(int* a, int n)
{
	int flag = 1;
	for (int i = n-1; i >0&&flag; i--)
	{
		flag = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j + 1] < a[j])
			{
				HoanVi(a[j + 1], a[j]);
				flag = 1;
			}
		}
	}
}
void MergeSort(int *a, int n)
{
	int* temp = new int[n];
	MergeSort_recur(a, 0, n - 1, temp);
	delete[]temp;
}
void MergeSort_recur(int *a, int l, int r, int* temp)
{
	if (!(l < r))
		return;
	int mid = (l + r) / 2;
	MergeSort_recur(a, l, mid, temp);
	MergeSort_recur(a, mid + 1, r, temp);
	Merge(a, l, r, mid, temp);
}
void Merge(int* a, int l, int r, int m, int* temp)
{
	int i = l, j = m+1;
	int k=l;
	for (int index = l; index < r+1; index++)
	{
		temp[index] = a[index];
	}
	while (i <= m && j <= r)
	{
		if (temp[i]<temp[j])
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
void QuickSort(int* a, int n)
{
	QuickSort_recur(a, 0, n - 1);
}
void QuickSort_recur(int* a, int l, int r)
{
	if (l >= r||l<0||right <0)
		return;
	int i = l, j = r;
	int x = a[(l + r) / 2];
	while (i<j)
	{
		while (a[i]<x) i++;
		while (x<a[j]) j--;
		if (i <= j)
		{
			HoanVi(a[i++], a[j--]);
		}
	}
	QuickSort_recur(a, l, j);
	QuickSort_recur(a, i, r);
}

void _sort(int order,int size,void(alg)(int*, int))
{
	int* a = new int[size];

	GenerateData(a, size, order);
	clock_t t;
	t = clock();
	alg(a, size);
	t = clock() - t;
	cout <<"\t\t" <<(double)t<<"ms"<<endl;
	cout << "\t\tdone! checking...";
	out << "," << (double)t ;
	cout<<check(a, size)<<endl;
	delete[] a;
}

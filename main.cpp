#include<iostream>
#include<time.h>
#include"DataGenerator.h"
#include"SortAlgorithm.h"
using namespace std;
void printOrder(int Order)
{
	switch (Order)
	{
	case 0:
	{
		cout << "Sap xep ngau nhien : \n";
		break;
	}
	case 1:
	{
		cout << "Gan nhu co thu tu : \n";
		break;
	}
	case 2:
	{
		cout << "Co thu tu : \n";
		break;
	}
	case 3:
	{
		cout << "Thu tu nguoc : \n";
		break;
	}
	default:
		break;
	}
}
void main()
{
	int DataOrder[4] = { 0,1,2,3 };
	int DataSize[5] = { 3000,10000,30000,100000,300000 };
	void (*Algorithm[7])(int* , int , int(*)(int, int)) = { &SelectionSort ,&InsertionSort,&BubbleSort,&MergeSort,&QuickSort/*QuickSort*/ };
	clock_t t;
	for (int i = 0; i < 4; i++)
	{
		printOrder(DataOrder[i]);
		for (int j = 0; j < 5; j++)
		{
			cout << "\t Size :" << DataSize[j] << endl;
			for (int k = 0; k < 5; k++)
			{
				cout << "\t\tAlgorithm : " << k << endl;
				t = clock();
				_sort(DataOrder[i], DataSize[j], Algorithm[k]);
				t = clock() - t;
				cout << "\t\tThoi gian thuc hien:" << (double)t / CLOCKS_PER_SEC << "s\n";
			}
		}
	}



	
}
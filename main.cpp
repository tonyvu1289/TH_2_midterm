#include<iostream>
#include<time.h>
#include<fstream>
#include"DataGenerator.h"
#include"SortAlgorithm.h"
#include "main.h"
std::ofstream out;
int DataOrder[4] = { 0,1,2,3 };
int DataSize[5] = { 5000,10000,30000,100000,300000 };
void (*Algorithm[7])(int*, int) = { &SelectionSort ,&InsertionSort,&BubbleSort,&MergeSort,&QuickSort,&HeapSort,&binaryInsertionSort};
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
		cout << "Co thu tu : \n";
		break;
	}
	case 2:
	{
		cout << "Thu tu nguoc : \n";
		break;
	}
	case 3:
	{
		cout << "Gan nhu co thu tu : \n";
		break;
	}
	default:
		break;
	}
}
void writeOrder(int Order)
{
	switch (Order)
	{
	case 0:
	{
		out << "Sap xep ngau nhien : \n";
		break;
	}
	case 1:
	{
		out << "Co thu tu : \n";
		break;
	}
	case 2:
	{
		out << "Thu tu nguoc : \n";
		break;
	}
	case 3:
	{
		out << "Gan nhu co thu tu : \n";
		break;
	}
	default:
		break;
	}
}
void writecsvRow()
{
	out << "Size";
	for (int i = 0; i < 7; i++)
	{
		out << ",Algorithm" << i;
	}
	out << "\n";
}
void main()
{
	out.open("result.csv", ios::out);
	clock_t t;
	for (int i = 0; i < 4; i++)
	{
		printOrder(DataOrder[i]);
		writeOrder(DataOrder[i]);
		writecsvRow();
		for (int j = 0; j < 5; j++)
		{
			cout << "\tDataSize : " << DataSize[j]<<"\n";
			out << DataSize[j];
			for (int k = 0; k < 7; k++)
			{
				cout << "\t\tAlgorithm : " << k << endl;
				_sort(DataOrder[i], DataSize[j], Algorithm[k]);
			}
			out << "\n";
		}
	}
	out.close();

	
}
#pragma once
#include <vector>
using std::vector;
class Sort
{
public:
	Sort(void);
	~Sort(void);
	static void  InsertSort(vector<int>& vec);
	static void quickSort(vector<int> &vec,int low, int high);
	static int partion(vector<int> &vec, int low,int high);
	static void shellSort(vector<int> &vec);
	static void simpleSelectSort(vector<int> &vec);
	static void HeapSort(vector<int> &vec, int len);
	static void AdjustDown(vector<int> &vec, int k, int len);
	static void buildHeap(vector<int> &vec, int len);
	static void swap(int &a, int &b);
	static void AdjustUp(vector<int> &vec, int k, int len);

	static void HeapSort1(vector<int> &vec, int len);
	static  void buildHeap1(vector<int> &vec, int len);
	static void bubbleSort(vector<int> &vec);

	static void mergeSort(vector<int> &vec, int low, int high);
	static void merge(vector<int> &vec, int low, int mid, int high);
	static void reverse(int a[], int i, int j);
	static void exchange(int a[], int low, int mid, int high);
	static void merge(int a[], int low, int mid, int high);
	static void mergeSort(int a[],int low, int high);
	static void countSort(int a[], int n);
	static void LSDSort(int a[], int n);
	static void bucketSort(int a[], int n);
	static int getBucketIndex(int a, int range);
};


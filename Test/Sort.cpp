#include "Sort.h"
#include <algorithm>
#include <vector>
#include <list>
Sort::Sort(void)
{
}


Sort::~Sort(void)
{
}

void  Sort::InsertSort(vector<int>& vec)
{
	if(vec.empty())
		return;
	for (int i = 1; i < vec.size();++i)
	{
		if (vec[i] < vec[i-1])
		{
			int temp = vec[i];
			int j = 0;
			for (j = i - 1;j >= 0&& temp < vec[j];--j)
				vec[j+1] = vec[j];
			vec[j+1] = temp;

		}
	}

}
void Sort::quickSort(vector<int> &vec,int low, int high)
{
	if(low > high)
		return;
	int i = partion(vec, low, high);
	if (low < i-1)
		quickSort(vec, low, i-1);
	if(high > i+1)
		quickSort(vec, i+1, high);

}
int Sort::partion(vector<int> &vec, int low, int high)
{
	int x = vec[low];
	int i = low;
	int j = high;
	while(i < j)
	{
		while(i < j && x <= vec[j])
			--j;
		vec[i] = vec[j];
		while(i < j && x >= vec[i])
			++i;
		vec[j] = vec[i];
	}
	vec[i] = x;
	return i;
}


void Sort::shellSort(vector<int> &vec)
{
	for (int gap = vec.size() / 2;gap > 0;gap = gap /2)
	{
		for (int i = 0;i < gap;i += 1)//分多少组，i为每一组的起始位置
		{
			for (int j = i+gap;j < vec.size();j+= gap)//j 表示每一组的第二个元素在哪，以第二个为标准往前插入针对每一组插入排序 （从后往前插入 记住直接插入排序）
			{
				int temp = vec[j];
				int m = 0;
				for (m = j - gap;m >= i && temp < vec[m];m -= gap)
					vec[m+gap] = vec[m];
				vec[m+gap] = temp; 
			}
		}
	}
}

void Sort::simpleSelectSort(vector<int> &vec)
{
	for (int i = 0; i < vec.size();++i)
	{
		int min = i;
		for (int j = i+1; j < vec.size();++j)
		{
			if(vec[j] <vec[min])
				min = j;
		}
		int temp = vec[i];
		vec[i] = vec[min];
		vec[min] = temp;

	}
}

void Sort::HeapSort(vector<int> &vec, int len)// 如a1 到a10, a10刚好是最后一个元素，a1就是最大的元素，将最大的元素放在a10的位置，直到只剩余一个元素
{
	buildHeap(vec, len);
	for (int i = len;i >=1; --i) //i为最后一个元素的下标
	{
		swap(vec[i],vec[1]);
		AdjustDown(vec, 1, i-1);
	}

}
void Sort::AdjustDown(vector<int> &vec, int i, int len)//len代表实际元素的个数
{
	int x = vec[i];
	for (int k = 2 * i;k <= len;k = 2 * i) // 这一层循环是针对当前父节点i，要去看i的子几点 2i  <= 的原因是最后一个节点也要考虑到
	{
		if(k < len && vec[k] < vec[k+1]) k++; //假如k是最后一个节点
		if(vec[k] <= x) break;
		else
		{
			vec[i] = vec[k];
			i = k;// 当前的i更新了，则子节点k也需要更新为 k = 2 * i
		}
	}
	vec[i] = x;
}
void Sort::swap(int &a, int &b)
{
	int temp =a;
	a = b;
	b = temp;
}
void Sort::buildHeap(vector<int> &vec,int len)//len为 参与排序的元素的个数
{
	for (int i = len / 2; i >= 1; --i) //数组空出第一个 从下标为1开始，所以长度减1
	{
		AdjustDown(vec, i, len);
	}

}

void Sort::AdjustUp(vector<int> &vec, int k, int len)
{
	int i = k / 2;
	int x = vec[k];
	for (;i >=1; i /= 2)
	{
		if(x < vec[i])
		{
			vec[k] = vec[i];
			k = i;
		}
		
	}
	vec[k] = x;
}

void Sort::bubbleSort(vector<int> &vec)
{

	for (int i = 0;i < vec.size()-1;++i)
	{
		for (int j = i + 1;j < vec.size();++j)
		{
			if (vec[i] > vec[j])
				swap(vec[i], vec[j]);
		}

	}
}

void Sort::mergeSort(vector<int> &vec, int low, int high)
{
	if(low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(vec,low,mid);
		mergeSort(vec,mid+1, high);
		merge(vec, low, mid, high);
	}
}

void Sort::merge(vector<int> &vec, int low, int mid, int high)
{
	vector<int> B(vec.size());//辅助空间大小要跟数组的原大小一样，下标才能一致
	for (int i = low;i <= high;++i)
	{
		B[i] = vec[i];
	}
	int j,k,m;
	for(j = low, k = mid+1, m = low; j <= mid && k <= high; m++)
	{
		if(B[k] < B[j])
			vec[m] = B[k++];
		else
			vec[m] = B[j++];
	}
	while(j <= mid) vec[m++] = B[j++];
	while(k <= high) vec[m++] = B[k++];
}
void Sort::mergeSort(int a[],int low, int high)
{
	if(low < high)
	{
		int mid = (low + high)/2;
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);
		merge(a,low, mid, high);
	}
}
void Sort::merge(int a[], int low, int mid, int high)
{
	int i = low; //[low,mid]
	int j = mid+1; //[low+1,high]
	while(i < j && j <= high)
	{
		while(i < j && a[i] <= a[j]) i++; //必须有 =
		int index = j; 
		while(j <= high && a[j] <= a[i]) j++;
		exchange(a,i,index-1,j-1); //把[index,j-1] 放到[i,index -1]前面
		i += j - index; //[index,j-1]的长度
	}
}
void Sort::exchange(int a[],int low, int mid, int high)
{
	reverse(a, low, mid);
	reverse(a, mid+1, high);
	reverse(a,low, high);
}

void Sort::reverse(int a[], int low, int high)
{
	while(low < high)
		swap(a[low++], a[high--]);
}

void Sort::countSort(int a[], int n)
{
	if(NULL == a)
		return;
	int min = a[0];
	int max = a[0];
	for (int i = 1;i < n;++i)
	{
		if(a[i] <min)
			min = a[i];
		if(a[i] > max)
			max = a[i];
	}
	int rang = (max -min) + 1;//如果是1001-2000 则映射到 0->1000 否则你的哈希表的长度就是0到2000浪费空间
	int size = rang + 1;
	int *count = new int[size];
	memset(count,0,sizeof(int)*size);
	for (int i = 0;i < n;++i)
	{
		count[a[i] - min]++;//数字映射
	}
	int k = 0;
	for (int j = 0; j < size;++j)
	{
		while(count[j]--)
		{
			a[k++]=j+min;//数字还原
		}
	}
	delete[] count;

}

void LSDOSort(int a[], const int n)
{
	int digitCount = 0;//统计最大位数
	for (int i = 0;i < n;++i)
	{
		while (pow(10.0,digitCount) < a[i])
		{
			digitCount++;
		}
	}

	for (int i = 0; i < digitCount;++i)
	{
		//统计个数
		int Digit[10]={0};
		int flag = 1;
		for (int j = 0;j < n; ++j)
		{
			Digit[(a[j]/flag)%10]++;
		}
		//保存每个数位的起始位置
		int begin[10]={0};
		for (int j = 1;j < 10;++j)
		{
			begin[j] = begin[j-1] + Digit[j-1];
		}
		//按某位的顺序保存到临时数组
		int *temp = new int[n];
		memset(temp, 0, sizeof(int) * n);
		for (int j = 0;j < n;++j)
		{
			int index = (a[j]/flag) % 10;
			temp[begin[index]++] = a[i];

		} 
		//将数据重新写入原空间
		for (int j = 0;j < n;++j)
			a[j] =temp[j];
		delete[] temp;
		flag *= 10;
	}

}

//对0 到 49 分到 5个桶 ，每个桶的范围是10 如0到9,10到19
void Sort::bucketSort(int a[], int n)
{
	using std::list;
	using std::vector;
	vector< vector<int> > buckets(5);//建立5个桶
	int range = 10;
	//将每个数放入桶中
	for (int i = 0;i < n;++i)
	{
		int pos = getBucketIndex(a[i],range);//获得桶号
		buckets[pos].push_back(a[i]);
	}
	int k = 0;
	for(int i = 0;i < buckets.size();++i)
	{
		quickSort(buckets[i],0, buckets[i].size() - 1);
		for (int j = 0; j < buckets[i].size();++j)
		{
			a[k++] = buckets[i].at(j);
		}
		
	}
}
int Sort::getBucketIndex(int a, int rang)
{
	return a/rang;
}
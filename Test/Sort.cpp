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
		for (int i = 0;i < gap;i += 1)//�ֶ����飬iΪÿһ�����ʼλ��
		{
			for (int j = i+gap;j < vec.size();j+= gap)//j ��ʾÿһ��ĵڶ���Ԫ�����ģ��Եڶ���Ϊ��׼��ǰ�������ÿһ��������� ���Ӻ���ǰ���� ��סֱ�Ӳ�������
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

void Sort::HeapSort(vector<int> &vec, int len)// ��a1 ��a10, a10�պ������һ��Ԫ�أ�a1��������Ԫ�أ�������Ԫ�ط���a10��λ�ã�ֱ��ֻʣ��һ��Ԫ��
{
	buildHeap(vec, len);
	for (int i = len;i >=1; --i) //iΪ���һ��Ԫ�ص��±�
	{
		swap(vec[i],vec[1]);
		AdjustDown(vec, 1, i-1);
	}

}
void Sort::AdjustDown(vector<int> &vec, int i, int len)//len����ʵ��Ԫ�صĸ���
{
	int x = vec[i];
	for (int k = 2 * i;k <= len;k = 2 * i) // ��һ��ѭ������Ե�ǰ���ڵ�i��Ҫȥ��i���Ӽ��� 2i  <= ��ԭ�������һ���ڵ�ҲҪ���ǵ�
	{
		if(k < len && vec[k] < vec[k+1]) k++; //����k�����һ���ڵ�
		if(vec[k] <= x) break;
		else
		{
			vec[i] = vec[k];
			i = k;// ��ǰ��i�����ˣ����ӽڵ�kҲ��Ҫ����Ϊ k = 2 * i
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
void Sort::buildHeap(vector<int> &vec,int len)//lenΪ ���������Ԫ�صĸ���
{
	for (int i = len / 2; i >= 1; --i) //����ճ���һ�� ���±�Ϊ1��ʼ�����Գ��ȼ�1
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
	vector<int> B(vec.size());//�����ռ��СҪ�������ԭ��Сһ�����±����һ��
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
		while(i < j && a[i] <= a[j]) i++; //������ =
		int index = j; 
		while(j <= high && a[j] <= a[i]) j++;
		exchange(a,i,index-1,j-1); //��[index,j-1] �ŵ�[i,index -1]ǰ��
		i += j - index; //[index,j-1]�ĳ���
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
	int rang = (max -min) + 1;//�����1001-2000 ��ӳ�䵽 0->1000 ������Ĺ�ϣ��ĳ��Ⱦ���0��2000�˷ѿռ�
	int size = rang + 1;
	int *count = new int[size];
	memset(count,0,sizeof(int)*size);
	for (int i = 0;i < n;++i)
	{
		count[a[i] - min]++;//����ӳ��
	}
	int k = 0;
	for (int j = 0; j < size;++j)
	{
		while(count[j]--)
		{
			a[k++]=j+min;//���ֻ�ԭ
		}
	}
	delete[] count;

}

void LSDOSort(int a[], const int n)
{
	int digitCount = 0;//ͳ�����λ��
	for (int i = 0;i < n;++i)
	{
		while (pow(10.0,digitCount) < a[i])
		{
			digitCount++;
		}
	}

	for (int i = 0; i < digitCount;++i)
	{
		//ͳ�Ƹ���
		int Digit[10]={0};
		int flag = 1;
		for (int j = 0;j < n; ++j)
		{
			Digit[(a[j]/flag)%10]++;
		}
		//����ÿ����λ����ʼλ��
		int begin[10]={0};
		for (int j = 1;j < 10;++j)
		{
			begin[j] = begin[j-1] + Digit[j-1];
		}
		//��ĳλ��˳�򱣴浽��ʱ����
		int *temp = new int[n];
		memset(temp, 0, sizeof(int) * n);
		for (int j = 0;j < n;++j)
		{
			int index = (a[j]/flag) % 10;
			temp[begin[index]++] = a[i];

		} 
		//����������д��ԭ�ռ�
		for (int j = 0;j < n;++j)
			a[j] =temp[j];
		delete[] temp;
		flag *= 10;
	}

}

//��0 �� 49 �ֵ� 5��Ͱ ��ÿ��Ͱ�ķ�Χ��10 ��0��9,10��19
void Sort::bucketSort(int a[], int n)
{
	using std::list;
	using std::vector;
	vector< vector<int> > buckets(5);//����5��Ͱ
	int range = 10;
	//��ÿ��������Ͱ��
	for (int i = 0;i < n;++i)
	{
		int pos = getBucketIndex(a[i],range);//���Ͱ��
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
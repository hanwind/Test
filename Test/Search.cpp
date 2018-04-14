#include "Search.h"


Search::Search(void)
{
}


Search::~Search(void)
{
}

int Search::binarySearch(vector<int> &vec, int a)
{
	int mid = 0;
	int low = 0;
	int high = vec.size() - 1;//��������û��Ԫ�ص�ʱ�� high = -1 low = 0, Ҳ����-1
	while(low <= high)//������ֻ��һ��Ԫ�ص�ʱ�� high = 0 = low
	{
		 mid = (low + high) / 2;
		if(vec[mid] == a)
			return mid;
		if (a < vec[mid])
		{
			high = mid - 1;
		}else
		{
			low = mid + 1;
		}

	}
	return -1;//�����ڵ�ʱ����δ��� ����-1

}
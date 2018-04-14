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
	int high = vec.size() - 1;//假如数组没有元素的时候 high = -1 low = 0, 也返回-1
	while(low <= high)//当数组只有一个元素的时候 high = 0 = low
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
	return -1;//不存在的时候如何处理 返回-1

}
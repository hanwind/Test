#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;
/************************************************************************/
/* ��ָoffer����Ŀ                                                                     */
/************************************************************************/
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> result(k,0);
		if(input.size() < k)
			return result;
		int index = partion(input, 0, input.size()-1);//�պõ�k��
		while(index != k-1)//ǰk�����±���k-1
		{
			if(k-1 < index)
			{
				index = partion(input, 0, index-1);
			}
			else
			{
				index = partion(input, index+1, input.size()-1);
			}


		}
		for(int i = 0;i < k;++i)
		{
			result[i] = input[i];
		}
		sort(result.begin(), result.end());
		return result;
	}
	int partion(vector<int> &vc, int low, int high)
	{
		int x = vc[low];
		int i = low;
		int j = high;
		while(i < j)
		{
			while(i < j && vc[j] >= x) --j;
			vc[i] = vc[j];
			while(i < j && vc[i] <= x) ++i;
			vc[j] = vc[i];
		}
		vc[i] = x;
		return i;
	}
};
/*
class Solution1{
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if(input.size() < k || k < 1)
			return vector<int>();
		multiset<int, greater<int> > sets;
		vector<int>::const_iterator iter = input.begin();
		while(iter != input.end())
		{
			if(sets.size() < k)
				sets.insert(*iter);
			else
			{
				multiset<int, greater<int> >::iterator it = sets.begin();
				if(*iter < *it)
				{
					sets.erase(it);
					sets.insert(*iter);
				}

			}
			iter++;
		}
		vector<int> output(k);
		vector<int>::iterator it1 = output.begin();
		multiset<int, greater<int> >::iterator it2 = sets.begin();
		for(;it1 != output.end() && it2 != sets.end();++it1, ++it2)
			*it1 = *it2;
		return output;
	}
};
*/
/*
class Solution2{
public:
	void Insert(int num)
	{
		int size = min.size() + max.size();
		if((size & 1) == 0)//���Ϊż��,��һ���Ȳ嵽С����
		{
			if(max.size() > 0 && num < max[0])
			{
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());

				num = max[0];
				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();

			}

			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());
		}else
		{
			if(min.size() > 0 && num > min[0])
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());

				num = min[0];
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}

			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		}

	}

	double GetMedian()
	{ 
		int size = min.size() + max.size();
		double median = 0;
		//if(size == 0)
		//hrow exception("No numbers are available");
		if((size & 1) == 1)//����
		{
			median = min[0];
		}else
		{
			median = (min[0]+max[0])/2.0;
		}
		return median;

	}
public:
	vector<int> min;//��С��
	vector<int> max;//����
};
*/
class Solution3 {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if(n < 0)
			return -1;
		ostringstream os;
		os<<n;
		string str = os.str();//ת��Ϊ�ַ���
		int length = str.size();
		int first = str[0] - '0';
		int digitFirst = 0;
		int digitOther = 0;
		if(length == 1 && n > 0)
			return 1;
		if(length == 1 && n == 0)
			return 0;
		string temp = str.substr(1, length-1);
		if(first > 1)
			digitFirst = pow(10.0,length-1);
		else if(first == 1)
			digitFirst = atoi(temp.c_str())+1;
		digitOther = first * (length-1) *pow(10.0, length-2);
		digitOther += NumberOf1Between1AndN_Solution(atoi(temp.c_str()));
		return digitFirst +digitOther;
	}
};
class Solution4
{
public:
	int getMaxValue(const vector<vector<int> > &gifts)
	{
		if(gifts.size() <= 0 || gifts[0].size() <= 0 )
			return -1;
		int row = gifts.size();
		int col = gifts[0].size();
		vector< vector<int> > dp(row,vector<int>(col, 0));
		for (int i = 0; i< row; ++i)
		{
			for (int j = 0; j < col;++j)
			{
				int left = 0;
				int up = 0;
				if(i > 0)
					left = dp[i-1][j];
				if(j > 0)
					up = dp[i][j-1];
				dp[i][j] = max(left, up) + gifts[i][j];
			}
		}
		return dp[row-1][col-1];

	}
};
/************************************************************************/
/* ��֦offer������47 ��������ֵ                                                                     */
/************************************************************************/
class Solution5
{

public:
	int getMaxValue(const vector<vector<int> > &gifts)const
	{
		if(gifts.size() <= 0 || gifts[0].size() <= 0)
			return -1;
		int row = gifts.size();
		int col = gifts[0].size();
		vector<int> dp(col, 0);
		for (int i = 0; i < row;++i)
		{
			for (int j = 0;j < col;++j)
			{
				int left = 0;
				int up = 0;
				if(i > 0)
					up = dp[j];
				if(j > 0)
					left = dp[j-1];
				dp[j] = max(left, up) + gifts[i][j];
			}
		}
		return dp[col-1];
	}
};

/************************************************************************/
/* ��ָoffer48 ����ظ��Ӵ�                                                                     */
/************************************************************************/
class Solution6{

public:
	int getMaxLength(const string & str)
	{
		if(str.size() <= 0)
			return 0;
		vector<int> position(26,-1);//�洢��һ���ַ����ֵ�λ�� a~z
		int curLength = 0;
		int maxLength = 0;
		int d = 0;
		for (int i = 0;i < str.size();++i)
		{
			int index = str[i]-'a';
			if(position[index] < 0) //��һ�γ���
			{
				curLength++;
			}	
			else
			{
				d = i - position[index];//��ʾ�ظ����ֵ��ַ����ϴγ���λ�õľ���
				curLength = (d <= curLength) ? d : curLength+1;
			}
			position[index] = i;//�����ַ����ֵ�λ��
			maxLength = max(maxLength, curLength);
		}
		return maxLength;
	}
};

class Solution7
{
public:
	

};
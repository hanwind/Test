#pragma once
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class s360
{
	int cal(vector<int> &temp, int n)
	{
		if (n <= 3) return 0;
		if (n == 4 || n == 5) return 1;
		else
		{
			if (2 * n - 3 > n)
			{

				return 2 + temp[n - 3];
			}

			else
				return min(0 + temp[n - 1], 1 + temp[n - 1]);
		}

	}
	void run()
	{
		int n = 0;
		while (cin >> n)
		{
			vector<int> temp(n + 1, 0);
			for (int i = 1; i <= n; i++)
				temp[i] = cal(temp, i);
			cout << temp[n] << endl;
		}
		return 0;
	}
};
class S3601
{
public:
	S3601();
	~S3601();
	int isInclude(vector<int> &a, vector<int> &b)
	{
		int temp = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i] == b[i])
				return false;
		}
		return true;
	}
	void run()
	{
		int n;
		while (cin >> n)
		{
			vector<vector<int>> temp;
			int k;
			for (int i = 0; i < n; ++i)
			{
				cin >> k;
				vector<int> temp1(k, 0);
				for (int j = 0; j < k; ++j)
				{
					int m = 0;
					cin >> m;
					temp1[j] = m;
				}
				temp.push_back(temp1);
			}
			vector<int> result(temp[0]);
			for (int i = 1; i < temp.size(); ++i)
			{
				if (result.size() <= temp[i].size())
				{
					if (isInclude(result, temp[i]))
					for (int j = 0; j < temp.size(); ++j)
						result.push_back(temp[j]);
					else
						swap(result, temp[i]);
				}

			}
		}
	}
private:

};

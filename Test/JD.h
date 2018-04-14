#pragma once
#include<iostream>
#include <vector>
using namespace std;
class JD1
{
public:
	JD1();
	~JD1();
	void run()
	{
		int n;
		while (cin >> n)
		{
			set<string> strs;
			for (int i = 0; i < n; ++i)
			{
				string temp;
				cin >> temp;
				strs.insert(temp);
			}
			int count = 0;

			for (auto i = strs.begin(); i != strs.end(); ++i)
			{
				if (isStr(*i))
					count++;
			}
			cout << count << endl;

		}
	}
	bool isStr(const string & str)
	{
		string str1 = str.substr(0, 2);
		string str2 = str.substr(3, 2);
		if (str1[0] == str2[0] && str1[1] == str2[1])
			return true;
		if (str1[0] == str2[1] && str1[1] == str2[0])
			return true;
		return false;
	}
};
class JD2
{
	void run()
	{
		int n;
		while (cin >> n)
		{
			vector<unsigned long long> nums(n, 0);
			for (int i = 0; i < n; ++i)
			{
				cin >> nums[i];
			}
			nums[0] = pow(2.0, 63);
			for (int i = 0; i < nums.size(); ++i)
			{
				unsigned long long k = nums[i];
				unsigned long long x = 0;
				unsigned long long y = 0;
				if (isInt(k, x, y))
					cout << x << " " << y << endl;
				else
					cout << "NO" << endl;
			}


		}
	}
	bool isInt(const unsigned long long &a, unsigned long long &x, unsigned long long &y)
	{
		unsigned long long temp = a;
		unsigned long long count = 0;
		unsigned long long flag = false;
		if (a % 2 == 1)
			return false;
		while (temp)
		{
			temp = temp / 2;
			count++;
			if (temp % 2 == 1)
			{
				flag = true;
				break;

			}
		}
		if (flag)
		{
			x = temp;
			y = pow(2.0, count);
			return true;
		}
		return false;

	}
};

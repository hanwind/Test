#pragma once
#include<vector>
using std::vector;
struct Less
{
	bool operator()(const vector<int> & a, const vector<int> &b)
	{
		return a.size() > b.size() ? true : false;
	}
};
/*bool Less(const vector<int> &a, const vector<int> &b)
{
return a.size() > b.size() ? true : false;
}
*/
template<typename T>
struct Show
{
	void operator()(T &vec)
	{
		cout << vec.size() << endl;
	}

};
template<>//模板的特化
struct Show<vector<int>>
{
	void operator()(vector<int> &vec)
	{
		cout << vec.size() << endl;
	}
};
/*void show(const vector<int> & vec)
{
	cout << vec.size() << endl;
}
*/

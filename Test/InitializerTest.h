#pragma once
#include<iostream>
#include<vector>
#include <iterator>
using namespace std;
/*
测试C++11的一致性初始化参数
本质是调用initializer_list<T>这个类模板
这个类里面指向一个array<T,n>的数组                                                     
*/
namespace test
{
	class P
	{
	public:
		P(int a, int b) :a(a), b(b)
		{
			cout << "P(int a, int b)" << endl;

		}
		P(initializer_list<int> initLisi)//就算这个函数是private的也会被编译器调用
		{
			cout << "P(initilizer_list<int> initList)" << endl;
			for (auto i : initLisi)
				cout << i << endl;
		}
		
		
		P(int a, int b, int c)
		{
			cout << "P(int a, int b, int c)" << endl;
		}
		/**
			测试目的:已大括号的方式初始化vector
		*/
		static void testVector1()
		{
			vector<int> vec{ 1, 2, 3, 4, 5, 6, 7 };
			copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
		}
		/*
		explict 新的特性
		将P(initializer_list<int> initLisi)注释掉
		且explicit P(int a, int b, int c)变为explicit
		*/
		static void testExplicit()
		{
			P p1 = { 1, 2,3};//rror C2440: “初始化”: 无法从“initializer-list”转换为“test::P”
		}
	private:
		int a;
		int b;
	};
	template<typename t, template<class> class Container>
	class XCLs
	{
	public:

	private:

	};
}

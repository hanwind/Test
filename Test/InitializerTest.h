#pragma once
#include<iostream>
#include<vector>
#include <iterator>
using namespace std;
/*
����C++11��һ���Գ�ʼ������
�����ǵ���initializer_list<T>�����ģ��
���������ָ��һ��array<T,n>������                                                     
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
		P(initializer_list<int> initLisi)//�������������private��Ҳ�ᱻ����������
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
			����Ŀ��:�Ѵ����ŵķ�ʽ��ʼ��vector
		*/
		static void testVector1()
		{
			vector<int> vec{ 1, 2, 3, 4, 5, 6, 7 };
			copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
		}
		/*
		explict �µ�����
		��P(initializer_list<int> initLisi)ע�͵�
		��explicit P(int a, int b, int c)��Ϊexplicit
		*/
		static void testExplicit()
		{
			P p1 = { 1, 2,3};//rror C2440: ����ʼ����: �޷��ӡ�initializer-list��ת��Ϊ��test::P��
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

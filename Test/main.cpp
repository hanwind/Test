#include<iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include<string>
#include<sstream>
using namespace std;
struct ListNode
{
	int val;
	ListNode * next;
};
/************************************************************************/
/* 创建链表                                                                     */
/************************************************************************/
ListNode * createList(const vector<int> & vec)
{
	ListNode * pHead = nullptr;
	if (vec.size() <= 0)
		return pHead;
	pHead = new ListNode{ vec[0], nullptr };
	ListNode * pCurrent = pHead;
	for (int i = 1; i < vec.size(); ++i)
	{
		ListNode * temp = new ListNode{ vec[i], nullptr };
		pCurrent->next = temp;
		pCurrent = pCurrent->next;
	}
	return pHead;
}
//创建有环的链表 第k个元素为环的入口
ListNode* createCycleList(const vector<int> &vec, int k)
{
	if (k > vec.size())
		return nullptr;
	ListNode *pHead = new ListNode{ vec[0], nullptr };
	ListNode *pCurrent = pHead;
	for (auto i = vec.begin()+1; i != vec.begin()+k; ++i)
	{
		auto temp = new ListNode{ *i, nullptr };
		pCurrent->next = temp;
		pCurrent = temp;

	}
	auto pNode = pCurrent;
	for (auto i = vec.begin() + k; i != vec.end(); ++i)
	{
		auto temp = new ListNode{ *i, nullptr };
		pNode->next = temp;
		pNode = pNode->next;
	}
	pNode->next = pCurrent;
	return pHead;
}
/************************************************************************/
/* 返回链表的最后一个节点                                                                     */
/************************************************************************/

auto getLastNode(ListNode * pHead)->decltype(pHead)
{
	if (pHead == nullptr)
		return nullptr;
	auto cur = pHead;
	while (cur->next != nullptr)
	{
		cur = cur->next;
	}
	return cur;
}
/************************************************************************/
/* 创建相交的链表                                                                     */
/************************************************************************/
void createIntersectedList(const vector<int> &partA, const vector<int> &partB, const vector<int> &common, ListNode *&pAHead, ListNode * &pBHead)
{
	auto pPartA = createList(partA);
	auto pPartB = createList(partB);
	auto lastA = getLastNode(pPartA);
	auto lastB = getLastNode(pPartB);
	auto commonHead = createList(common);
	lastA->next = commonHead;
	lastB->next = commonHead;
	pAHead = pPartA;
	pBHead = pPartB;
}
/************************************************************************/
/* 链表反转                                                                     */
/************************************************************************/
ListNode * listReverse(ListNode * pHead)
{
	if (pHead == nullptr || pHead->next == nullptr)
		return pHead;
	ListNode * reverseHead = nullptr;
	ListNode *pCurrent = pHead;
	ListNode * pTemp = nullptr;
	while (pCurrent)
	{
		pTemp = pCurrent;
		pCurrent = pCurrent->next;
		pTemp->next = reverseHead;
		reverseHead = pTemp;
		
	}
	return reverseHead;
}
/************************************************************************/
/* 打印链表的仿函数                                                                     */
/************************************************************************/
struct Print
{
	void operator()(const ListNode &p)
	{
		cout << p.val << endl;
	}

};
/************************************************************************/
/* 测试链表反转的结果 
时间复杂度O（n）
/************************************************************************/
void testList1()
{
	vector<int> vec{1,2,3,4,5,6};
	ListNode * pHead = createList(vec);
	pHead = listReverse(pHead);
	ListNode * pCurrent = pHead;
	while (pCurrent != nullptr)
	{
		cout << (pCurrent->val) << endl;
		pCurrent = pCurrent->next;
	}
	//for_each(pHead, pHead + vec.size(), Print());
}
/************************************************************************/
/* 得到链表的倒数第k个节点  k 为1到k  
*思路：一个指针指向第1个节点，一个指向第k个节点
时间复杂度O（n）
/************************************************************************/
ListNode * RGetKNode(ListNode *pHead, size_t k)
{
	if (pHead == nullptr || k <= 1)
		return pHead;
	ListNode * pCurrentNode = pHead;
	while (pCurrentNode != nullptr && k > 1)//跳过k-1个节点，指向第K个节点，当k==1的时候结束while
	{
		pCurrentNode = pCurrentNode->next;
		--k;
	}
	if (pCurrentNode == nullptr && k >= 1)//节点的个数小于 k
		return nullptr;
	ListNode* pNode = pHead;
	while (pCurrentNode->next != nullptr)//终止条件是k指向最后一个节点，一个指针指向第k个节点
	{
		pCurrentNode = pCurrentNode->next;
		pNode = pNode->next;
		
	}
	return pNode;

}
/************************************************************************/
/* 测试得到链表的倒数第k个节点                                                                     */
/************************************************************************/
void testRgetKNode()
{
	vector<int> temp1{1,2,3,4,5,6};
	int k1 = 7;
	int k2 = 1;
	int k3 = 2;
	ListNode * pHead = createList(temp1);
	if (RGetKNode(pHead, k1) != nullptr)
		cout << RGetKNode(pHead, k1)->val << endl;
	else
		cout << "NULL" << endl;
	
	if (RGetKNode(pHead, k2) != nullptr)
		cout << RGetKNode(pHead, k2)->val << endl;
	else
		cout << "NULL" << endl;

	if (RGetKNode(pHead, k3) != nullptr)
		cout << RGetKNode(pHead, k3)->val << endl;
	else
		cout << "NULL" << endl;

}
/************************************************************************/
/* 获取链表的中间节点 N/2+1                                                                     */
/* 所有的指针初始指向头节点，一个指针移动的速度是2步pA，慢指针移动一步pB，知道快指针指向最终的节点，慢指针所指就是中间节点                                                               */
/*注意1个节点和2节点的情况，2个节点的时候你怎么移动两步*/
/************************************************************************/
ListNode *  GetMiddleNode(ListNode * pHead)
{
	if (pHead == nullptr || pHead->next == nullptr)//只有一个节点或者没有节点
		return pHead;
	auto *pA = pHead;
	auto * pB = pHead;
	while (pA->next != nullptr)
	{
		pA = pA->next;
		pB = pB->next;
		if (pA->next != nullptr)//指向最后一个节点
			pA = pA->next;

	}
	return pB;
}
/************************************************************************/
/* 测试返回链表中间节点的函数                                                                     */
/************************************************************************/
void testGetMiddleNode()
{
	vector<int> vec1{1,2,3,4,5,6};
	vector<int> vec2{ 1, 2, 3, 4, 5 };
	vector<int> vec3{ 1, 2 };
	vector<int> vec4{1 };
	auto pHead = createList(vec4);
	auto pNode = GetMiddleNode(pHead);
	if (pNode != nullptr)
		cout << pNode->val << endl;
	else
	cout << "NO" << endl;

}
/************************************************************************/
/* 从尾到头打印链表 递归版本 和非递归版本                                                                   */
/************************************************************************/
void PrintList(ListNode * pHead)//系统使用栈
{
	if (pHead == nullptr)
		return;
	else
	{
		PrintList(pHead->next);
		cout << pHead->val << endl;
	}

}
void _PrintList(ListNode * pHead)
{
	stack<decltype(pHead)> st;
	decltype(pHead) pNode = pHead;
	while (pNode != nullptr)
	{
		st.push(pNode);
		pNode = pNode->next;
	}
	while (!st.empty())
	{
		cout << st.top()->val << endl;
		st.pop();
	}


}

/************************************************************************/
/* 测试从尾到头打印链表(递归版本)                                                                     */
/************************************************************************/
void testPrintList()
{
	vector<int> vec{ 1, 2, 3, 4, 5, 6 };
	auto pHead = createList(vec);
	PrintList(pHead);
}
/************************************************************************/
/* 测试从尾到头打印链表(非递归版本 用栈实现)                                                                     */
/************************************************************************/
void _testPrintList()
{
	vector<int> vec{ 1, 2, 3, 4, 5, 6 };
	auto pHead = createList(vec);
	_PrintList(pHead);
}
/************************************************************************/
/* 6. 已知两个单链表pHead1 和pHead2 各自有序，把它们合并成一个链表依然有序
合并两个有序链表递归与非递归     只需要O（1）的空间。时间复杂度为O（max(len1, len2)）                                                                */
/************************************************************************/
auto mergeList(ListNode* pAHead, ListNode * pBHead) -> decltype(pAHead)//递归版本
{

	if (pAHead == nullptr)
		return pBHead;
	if (pBHead == nullptr)
		return pAHead;
	ListNode * mergerHead = nullptr;
	if (pAHead->val < pBHead->val)
	{
		mergerHead = pAHead;
		mergerHead->next = mergeList(pAHead->next, pBHead);
	}
	else
	{
		mergerHead = pBHead;
		mergerHead->next = mergeList(pAHead, pBHead->next);
	}
	return mergerHead;
}
auto _mergeList(ListNode * pAHead, ListNode *pBHead)->decltype(pAHead)
{
	ListNode * mergeHead = nullptr;
	if (pAHead == nullptr)
		return pBHead;
	if (pBHead == nullptr)
		return pAHead;
	if (pAHead->val < pBHead->val)
	{
		mergeHead = pAHead;
		pAHead = pAHead->next;
	}
	else
	{
		mergeHead = pBHead;
		pBHead = pBHead->next;
	}
	auto pCurrent = mergeHead;
	while (pAHead != nullptr && pBHead != nullptr)
	{
		if (pAHead->val < pBHead->val)
		{
			pCurrent->next = pAHead;
			pAHead = pAHead->next;
		}
		else
		{
			pCurrent->next = pBHead;
			pBHead = pBHead->next;
		}
		pCurrent = pCurrent->next;
		pCurrent->next = nullptr;//
	}
	if (pAHead != nullptr)
		pCurrent->next = pAHead;
	if (pBHead != nullptr)
		pCurrent->next = pBHead;
	return mergeHead;
}
//测试合并的递归版本
void testMergerList()
{
	vector<int> vecA{1,2,3,4,5,6};
	decltype(vecA) vecB{4,5,7,8,9};
	auto pAHeaad = createList(vecA);
	auto pBHead = createList(vecB);
	auto mergeHead = mergeList(pAHeaad, pBHead);
	PrintList(mergeHead);

}
//测试合并链表的非递归版本
void _testMergerList()
{
	vector<int> vecA{ 1, 2, 3, 4, 5, 6 };
	decltype(vecA) vecB{ 4, 5, 7, 8, 9 };
	auto pAHeaad = createList(vecA);
	auto pBHead = createList(vecB);
	auto mergeHead = _mergeList(pAHeaad, pBHead);
	PrintList(mergeHead);
}
/************************************************************************/
/*  7. 判断一个单链表中是否有环

这里也是用到两个指针。如果一个链表中有环，也就是说用一个指针去遍历，是永远走不到头的。
因此，我们可以用两个指针去遍历，一个指针一次走两步(Ahead 在什么前面)，一个指针一次走一步(Behind 在什么后面)，如果有环，两个指针肯定会在环中相遇。
时间复杂度为O（n）。                                                                    */
/************************************************************************/
bool HasCycle(ListNode * pHead)
{
	if (pHead == nullptr)
		return false;
	auto pAhead = pHead;//快指针一次走两步
	auto pBehind = pHead;//慢指针一次走一步
	while (pAhead != nullptr && pAhead ->next != nullptr)
	{      
		pAhead = pAhead->next->next;//这边用了就必须保证pAhead ！= nullptr 且pHead->next ！= nullptr(假如只有一个节点程序就奔溃了)
		pBehind = pBehind->next;
		if (pAhead == pBehind)
			return true;
	}
	return false;
}
void testHasCycle()
{
	//vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> vec{ 1 };
	//auto pHead = createCycleList(vec, 10);
	auto pHead = createList(vec);
	cout << HasCycle(pHead) << endl;
}
/************************************************************************/
/* 8. 判断两个单链表是否相交

如果两个链表相交于某一节点，那么在这个相交节点之后的所有节点都是两个链表所共有的。
也就是说，如果两个链表相交，那么最后一个节点肯定是共有的。
先遍历第一个链表，记住最后一个节点，然后遍历第二个链表，到最后一个节点时和第一个链表的最后一个节点做比较，
如果相同，则相交，否则不相交。时间复杂度为O(len1+len2)，因为只需要一个额外指针保存最后一个节点地址，空间复杂度为O(1)                                                                     */
/************************************************************************/
bool IsIntersected(ListNode *pAHead, ListNode * pBHead)
{
	if (pAHead == nullptr || pBHead == nullptr)
		return false;
	auto *pANode = pAHead;
	while (pANode->next != nullptr)
		pANode = pANode->next;
	auto *pBNode = pBHead;
	while (pBNode->next != nullptr)
		pBNode = pBNode->next;
	return pANode == pBNode ? true : false;
}
//保证已经相交
auto IntersectedNode(ListNode *pAHead, ListNode * pBHeaad)->decltype(pAHead)
{
	if (pAHead == nullptr || pBHeaad == nullptr)
		return nullptr;
	auto pANode = pAHead;
	int lenA = 0;
	while (pANode != nullptr)
	{
		lenA++;
		pANode = pANode->next;

	}
	auto pBNode = pBHeaad;
	int lenB = 0;
	while (pBNode != nullptr)
	{
		lenB++;
		pBNode = pBNode->next;

	}
	pANode = pAHead;
	pBNode = pBHeaad;
	if (lenA >= lenB)
	{
		int diss = lenA - lenB;
		while (diss > 0)
		{
			pANode = pANode->next;
			diss--;
			
		}
	}
	else
	{
		int diss = lenB - lenA;
		while (diss > 0)
		{
			pBNode = pBNode->next;
			diss--;

		}

	}
	auto IntersectedNode = pANode;
	while (pANode != nullptr && pBNode != nullptr)
	{
		if (pANode == pBNode)
		{
			IntersectedNode = pANode;
			break;
		}
		else
		{
			pANode = pANode->next;
			pBNode = pBNode->next;
		}
	}
	return IntersectedNode;
}
//测试相交链表算法
void testIntersectedNode()
{
	/*vector<int> partA{ 1, 2, 3, 4,5,6};
	decltype(partA) partB{1,2,3};
	decltype(partA) commonC{7,8,9};
	*/
	/*vector<int> partA{ 1, 2 };
	vector<int> partB{ 1, 2 };
	vector<int> commonC{ 3 };
	*/
	vector<int> partA{1};
	vector<int> partB{ 1, 2 };
	vector<int> commonC{ 3 };
	ListNode * pAHead = nullptr;
	ListNode * pBHead = nullptr;
	createIntersectedList(partA, partB, commonC, pAHead, pBHead);
	cout << IntersectedNode(pAHead, pBHead)->val<<"\n";
}
/*
将一个int转换为string
1.int是包含正负数的
因此一个符号的处理
*/
string Int_To_String(const int a)
{
	string str1;
	string str2;
	bool flag = false;
	int m = a;
	if (a == 0)
		str1.push_back('0');
	if (a < 0)
	{
		flag = true;//表示是负数
		m = 0 - a;
	}
	while (m > 0)
	{
		char ch = m % 10 + '0';
		str1.push_back(ch);
		m /= 10;
	}
	if (flag)
		str2.push_back('-');
	for (auto i = str1.rbegin(); i != str1.rend(); ++i)//使用反向迭代器从最后一个元素往前，往前就是++，往后就是--
	{
		str2.push_back(*i);

	}
	return str2;

}
/*
时间:2018.04.13 22:51
测试将一个int转换为string类型
*/
void testInt_To_String()
{
	int a1 = -10;
	int a2 = 0;
	int a3 = 123;
	cout << Int_To_String(a1) << endl;
	cout << Int_To_String(a2) << endl;
	cout << Int_To_String(a3) << endl;
}
/*
需求：将一个string转换为int
考虑：为什么将返回值是设为long long呢？你需要的是一个int 但是，当你的int超过int的最大值或者最小值的时候，我需要判断出来告诉你越界了
考点：
2--空字符处理
3--正号与负号的处理
4--溢出处理
5--如果遇到异常字符怎么处理
*/
long long String_To_Int(const string & str, bool &flag)//flag 表示是否转换成功
{
	long long sum = 0;
	if (str.size() <= 0)//2已处理
	{
		flag = false;
		return sum;
	}
	int tag = 1;//表示是正数还是负数
	auto i = str.begin();
	if (str[0] == '-')//3已处理
	{
		tag = -1;
		i++;
	}
	if (str[0] == '+')
	{
		i++;
	}
	while (i != str.end())
	{
		char ch = *i;
		if (ch >= '0' && ch <= '9')
		{
			sum = sum * 10 + tag*(ch - '0');
			if ((tag == 1 && sum > 0x7FFFFFFF) || (tag == -1 && sum < 0x10000000))//判断是否超过int的最大值和最小值 4已处理
			{
				flag = false;
				return 0;
			}
		}
		else//5异常已处理
		{
			flag = false;
			return 0;
		}
		++i;
	}
	return sum;
}
/*
测试将string 转换为int 注意异常的处理
*/
void testString_To_Int()
{
	string str1{ "123" };
	string str2{ "-123" };
	string str3{ "+123" };
	string str4{ "a123" };
	string str5{ "12a3" };
	string str6{ "123a" };
	string str7{ "2147483648" };
	cout << INT_MAX << endl;
	bool flag = true;
	cout << String_To_Int(str1,flag) << endl;
	flag = true;
	cout << flag<<String_To_Int(str2, flag) << endl;
	flag = true;
	cout << flag << String_To_Int(str3, flag) << endl;
	flag = true;
	cout << flag << String_To_Int(str4, flag) << endl;
	flag = true;
	cout << flag << String_To_Int(str5, flag) << endl;
	flag = true;
	cout << flag << String_To_Int(str6, flag) << endl;
	flag = true;
	cout << flag << String_To_Int(str7, flag) << endl;
}
//练习c++自带的库函数int与string的互相转换
/*
一、int转换成string
Ⅰ、to_string函数
c++11标准增加了全局函数std::to_string:
string to_string(int val);
string to_string(long val);
string to_string(long long val);
string to_string(unsigned val);
string to_string(unsigned long val);
string to_string(unsigned long long val);
string to_string(float val);
string to_string(double val);
string to_string(long double val);

Ⅱ、借助字符串流
　　标准库定义了三种类型字符串流：istringstream,ostringstream,stringstream，
  看名字就知道这几种类型和iostream中的几个非常类似，分别可以读、写以及读和写string类型，它们也确实是从iostream类型派生而来的。
  要使用它们需要包含sstream头文件。
  除了从iostream继承来的操作
 1.sstream类型定义了一个有string形参的构造函数，即：  stringstream stream(s); 创建了存储s副本的stringstream对象,s为string类型对象
2.定义了名为str的成员，用来读取或设置stringstream对象所操纵的string值：stream.str(); 返回stream中存储的string类型对象stream.str(s); 将string类型的s复制给stream，返回void
*/
void IntVSString()
{
	//将int转换为string
	int a = 10;//法一
	//string str1(a);string 不接受int的参数
	string str2 = to_string(a);//参数可以是int doubler

	stringstream ss;//法2
	ss << a;
	string str3 = ss.str();

	//将string 转换为int
	string str4 = "123";
	int b = atoi(str4.c_str());

	istringstream is(str4);////构造输入字符串流，流的内容初始化为“12”的字符串 
	int c;
	is >> c;////从is流中读入一个int整数存入i中  
	
}
/*
需求：获取一个目录下的内存最大的文件，提供设判断文件夹里有没有子文件夹的函数和计算文件的内存的函数已给出。
注意：一个目录下面还有目录和文件。
File * getMaxFiley(File *dir)
{
    if(dir == null || !dir->hasFile())
	return nullptr;
	list<File *> files = dir->listFiles();//获得当前目录下的所有文件列表
	File * file = files->first();//获取第一个文件
	for(auto i = files.begin(); i != files.end();++i)
	{
		
		if(i->isDirctory())
		{
		     File * temp = getMaxFile(*i);//递归获得当前文件的最大目录
			 if(file == nullptr&& temp != null)
				file = temp;
			  if(temp ！= nullptr && temp->getSize() > file->getSize())//当一个目录为空的时候
					file = temp;
		}else
		{
			if(i->getSize() > file->getSize())
				file = *i;
		}
	}
	return file;

	

}

*/
int main()
{
	testString_To_Int();
	return 0;
}


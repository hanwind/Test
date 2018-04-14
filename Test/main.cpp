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
/* ��������                                                                     */
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
//�����л������� ��k��Ԫ��Ϊ�������
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
/* ������������һ���ڵ�                                                                     */
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
/* �����ཻ������                                                                     */
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
/* ����ת                                                                     */
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
/* ��ӡ����ķº���                                                                     */
/************************************************************************/
struct Print
{
	void operator()(const ListNode &p)
	{
		cout << p.val << endl;
	}

};
/************************************************************************/
/* ��������ת�Ľ�� 
ʱ�临�Ӷ�O��n��
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
/* �õ�����ĵ�����k���ڵ�  k Ϊ1��k  
*˼·��һ��ָ��ָ���1���ڵ㣬һ��ָ���k���ڵ�
ʱ�临�Ӷ�O��n��
/************************************************************************/
ListNode * RGetKNode(ListNode *pHead, size_t k)
{
	if (pHead == nullptr || k <= 1)
		return pHead;
	ListNode * pCurrentNode = pHead;
	while (pCurrentNode != nullptr && k > 1)//����k-1���ڵ㣬ָ���K���ڵ㣬��k==1��ʱ�����while
	{
		pCurrentNode = pCurrentNode->next;
		--k;
	}
	if (pCurrentNode == nullptr && k >= 1)//�ڵ�ĸ���С�� k
		return nullptr;
	ListNode* pNode = pHead;
	while (pCurrentNode->next != nullptr)//��ֹ������kָ�����һ���ڵ㣬һ��ָ��ָ���k���ڵ�
	{
		pCurrentNode = pCurrentNode->next;
		pNode = pNode->next;
		
	}
	return pNode;

}
/************************************************************************/
/* ���Եõ�����ĵ�����k���ڵ�                                                                     */
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
/* ��ȡ������м�ڵ� N/2+1                                                                     */
/* ���е�ָ���ʼָ��ͷ�ڵ㣬һ��ָ���ƶ����ٶ���2��pA����ָ���ƶ�һ��pB��֪����ָ��ָ�����յĽڵ㣬��ָ����ָ�����м�ڵ�                                                               */
/*ע��1���ڵ��2�ڵ�������2���ڵ��ʱ������ô�ƶ�����*/
/************************************************************************/
ListNode *  GetMiddleNode(ListNode * pHead)
{
	if (pHead == nullptr || pHead->next == nullptr)//ֻ��һ���ڵ����û�нڵ�
		return pHead;
	auto *pA = pHead;
	auto * pB = pHead;
	while (pA->next != nullptr)
	{
		pA = pA->next;
		pB = pB->next;
		if (pA->next != nullptr)//ָ�����һ���ڵ�
			pA = pA->next;

	}
	return pB;
}
/************************************************************************/
/* ���Է��������м�ڵ�ĺ���                                                                     */
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
/* ��β��ͷ��ӡ���� �ݹ�汾 �ͷǵݹ�汾                                                                   */
/************************************************************************/
void PrintList(ListNode * pHead)//ϵͳʹ��ջ
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
/* ���Դ�β��ͷ��ӡ����(�ݹ�汾)                                                                     */
/************************************************************************/
void testPrintList()
{
	vector<int> vec{ 1, 2, 3, 4, 5, 6 };
	auto pHead = createList(vec);
	PrintList(pHead);
}
/************************************************************************/
/* ���Դ�β��ͷ��ӡ����(�ǵݹ�汾 ��ջʵ��)                                                                     */
/************************************************************************/
void _testPrintList()
{
	vector<int> vec{ 1, 2, 3, 4, 5, 6 };
	auto pHead = createList(vec);
	_PrintList(pHead);
}
/************************************************************************/
/* 6. ��֪����������pHead1 ��pHead2 �������򣬰����Ǻϲ���һ��������Ȼ����
�ϲ�������������ݹ���ǵݹ�     ֻ��ҪO��1���Ŀռ䡣ʱ�临�Ӷ�ΪO��max(len1, len2)��                                                                */
/************************************************************************/
auto mergeList(ListNode* pAHead, ListNode * pBHead) -> decltype(pAHead)//�ݹ�汾
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
//���Ժϲ��ĵݹ�汾
void testMergerList()
{
	vector<int> vecA{1,2,3,4,5,6};
	decltype(vecA) vecB{4,5,7,8,9};
	auto pAHeaad = createList(vecA);
	auto pBHead = createList(vecB);
	auto mergeHead = mergeList(pAHeaad, pBHead);
	PrintList(mergeHead);

}
//���Ժϲ�����ķǵݹ�汾
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
/*  7. �ж�һ�����������Ƿ��л�

����Ҳ���õ�����ָ�롣���һ���������л���Ҳ����˵��һ��ָ��ȥ����������Զ�߲���ͷ�ġ�
��ˣ����ǿ���������ָ��ȥ������һ��ָ��һ��������(Ahead ��ʲôǰ��)��һ��ָ��һ����һ��(Behind ��ʲô����)������л�������ָ��϶����ڻ���������
ʱ�临�Ӷ�ΪO��n����                                                                    */
/************************************************************************/
bool HasCycle(ListNode * pHead)
{
	if (pHead == nullptr)
		return false;
	auto pAhead = pHead;//��ָ��һ��������
	auto pBehind = pHead;//��ָ��һ����һ��
	while (pAhead != nullptr && pAhead ->next != nullptr)
	{      
		pAhead = pAhead->next->next;//������˾ͱ��뱣֤pAhead ��= nullptr ��pHead->next ��= nullptr(����ֻ��һ���ڵ����ͱ�����)
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
/* 8. �ж������������Ƿ��ཻ

������������ཻ��ĳһ�ڵ㣬��ô������ཻ�ڵ�֮������нڵ㶼���������������еġ�
Ҳ����˵��������������ཻ����ô���һ���ڵ�϶��ǹ��еġ�
�ȱ�����һ��������ס���һ���ڵ㣬Ȼ������ڶ������������һ���ڵ�ʱ�͵�һ����������һ���ڵ����Ƚϣ�
�����ͬ�����ཻ�������ཻ��ʱ�临�Ӷ�ΪO(len1+len2)����Ϊֻ��Ҫһ������ָ�뱣�����һ���ڵ��ַ���ռ临�Ӷ�ΪO(1)                                                                     */
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
//��֤�Ѿ��ཻ
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
//�����ཻ�����㷨
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
��һ��intת��Ϊstring
1.int�ǰ�����������
���һ�����ŵĴ���
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
		flag = true;//��ʾ�Ǹ���
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
	for (auto i = str1.rbegin(); i != str1.rend(); ++i)//ʹ�÷�������������һ��Ԫ����ǰ����ǰ����++���������--
	{
		str2.push_back(*i);

	}
	return str2;

}
/*
ʱ��:2018.04.13 22:51
���Խ�һ��intת��Ϊstring����
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
���󣺽�һ��stringת��Ϊint
���ǣ�Ϊʲô������ֵ����Ϊlong long�أ�����Ҫ����һ��int ���ǣ������int����int�����ֵ������Сֵ��ʱ������Ҫ�жϳ���������Խ����
���㣺
2--���ַ�����
3--�����븺�ŵĴ���
4--�������
5--��������쳣�ַ���ô����
*/
long long String_To_Int(const string & str, bool &flag)//flag ��ʾ�Ƿ�ת���ɹ�
{
	long long sum = 0;
	if (str.size() <= 0)//2�Ѵ���
	{
		flag = false;
		return sum;
	}
	int tag = 1;//��ʾ���������Ǹ���
	auto i = str.begin();
	if (str[0] == '-')//3�Ѵ���
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
			if ((tag == 1 && sum > 0x7FFFFFFF) || (tag == -1 && sum < 0x10000000))//�ж��Ƿ񳬹�int�����ֵ����Сֵ 4�Ѵ���
			{
				flag = false;
				return 0;
			}
		}
		else//5�쳣�Ѵ���
		{
			flag = false;
			return 0;
		}
		++i;
	}
	return sum;
}
/*
���Խ�string ת��Ϊint ע���쳣�Ĵ���
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
//��ϰc++�Դ��Ŀ⺯��int��string�Ļ���ת��
/*
һ��intת����string
��to_string����
c++11��׼������ȫ�ֺ���std::to_string:
string to_string(int val);
string to_string(long val);
string to_string(long long val);
string to_string(unsigned val);
string to_string(unsigned long val);
string to_string(unsigned long long val);
string to_string(float val);
string to_string(double val);
string to_string(long double val);

�򡢽����ַ�����
������׼�ⶨ�������������ַ�������istringstream,ostringstream,stringstream��
  �����־�֪���⼸�����ͺ�iostream�еļ����ǳ����ƣ��ֱ���Զ���д�Լ�����дstring���ͣ�����Ҳȷʵ�Ǵ�iostream�������������ġ�
  Ҫʹ��������Ҫ����sstreamͷ�ļ���
  ���˴�iostream�̳����Ĳ���
 1.sstream���Ͷ�����һ����string�βεĹ��캯��������  stringstream stream(s); �����˴洢s������stringstream����,sΪstring���Ͷ���
2.��������Ϊstr�ĳ�Ա��������ȡ������stringstream���������ݵ�stringֵ��stream.str(); ����stream�д洢��string���Ͷ���stream.str(s); ��string���͵�s���Ƹ�stream������void
*/
void IntVSString()
{
	//��intת��Ϊstring
	int a = 10;//��һ
	//string str1(a);string ������int�Ĳ���
	string str2 = to_string(a);//����������int doubler

	stringstream ss;//��2
	ss << a;
	string str3 = ss.str();

	//��string ת��Ϊint
	string str4 = "123";
	int b = atoi(str4.c_str());

	istringstream is(str4);////���������ַ��������������ݳ�ʼ��Ϊ��12�����ַ��� 
	int c;
	is >> c;////��is���ж���һ��int��������i��  
	
}
/*
���󣺻�ȡһ��Ŀ¼�µ��ڴ������ļ����ṩ���ж��ļ�������û�����ļ��еĺ����ͼ����ļ����ڴ�ĺ����Ѹ�����
ע�⣺һ��Ŀ¼���滹��Ŀ¼���ļ���
File * getMaxFiley(File *dir)
{
    if(dir == null || !dir->hasFile())
	return nullptr;
	list<File *> files = dir->listFiles();//��õ�ǰĿ¼�µ������ļ��б�
	File * file = files->first();//��ȡ��һ���ļ�
	for(auto i = files.begin(); i != files.end();++i)
	{
		
		if(i->isDirctory())
		{
		     File * temp = getMaxFile(*i);//�ݹ��õ�ǰ�ļ������Ŀ¼
			 if(file == nullptr&& temp != null)
				file = temp;
			  if(temp ��= nullptr && temp->getSize() > file->getSize())//��һ��Ŀ¼Ϊ�յ�ʱ��
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


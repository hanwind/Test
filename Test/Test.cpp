#include "Test.h"
#include "MyClass.h"
#include "BinaryTree.h"
#include "CQueue.h"
#include <vector>
#include "Sort.h"
#include "Search.h"
#include "Bit.h"
#include <algorithm>
#include <bitset>
#include <set>
#include "Solutions.h"
using std::cout;
using std::endl;
using std::vector;
void test::testCal()
{
	int n = 4;
	int a[] ={2,3,4,5};
	int *p = a;
	int *result = cal(p,n);
	for (int i = 0;i < n;++i)
	{
		std::cout<<*result++<<endl;
	}
}
void test::testRotate()
{
	int  a[2][2] = {1,2,3,4};
	int *p = &a[0][0];
	int n = 2;
	rotate(a);
	for (int i = 0;i < n*n;++i)
	{
		std::cout<<*p++<<std::endl;
	}
}
void test::testSmallLarge()
{
	int a[] = {7,10,2,6,19,22,32};
	int * rightMin = new int[7]; 
	smallLarge(a,rightMin,7);
}
void test::testFunction()
{
	int data[] = {0,1,2,1,1,3,4};
	int axis = function(data,7);
	std::cout<<axis<<std::endl;
}
void test::testGet_nextval()
{
	const char *p = "abab";
	char *src = "abacababc";
	int plen = strlen(p);
	int slen = strlen(src);
	int *nextval = new int[plen];
	get_nextval(p,plen,nextval);
	std::cout<<"nextval[i]:"<<std::endl;
	for (int i = 0;i < plen;++i)
	{
		std::cout<<nextval[i]<<std::endl;
	}
	std::cout<<"position"<<kmp(src,slen,p,plen,nextval,0)<<std::endl;
	
}
void test::testfindChildStr()
{
	char *src = "AABCD";
	char *des = "CEAA";
	std::cout<<findChildStr(src,des)<<std::endl;
}
void test::testStrToInt()
{
	char *src = "-112";
	std::cout<<strToInt(src)<<std::endl;
}
void test::testMultiply()
{
	char *a = "123";
	char *b = "45";
	multiply(a,b);
}
void test::testReverseSentence()
{
	char pa[] = "Today is Friday!";//注意char *p ="Today is Friday!";定义的是常量字符串不能更改
	std::cout<<ReverseSentence(pa)<<std::endl;
}
void test::testBitOrder()
{
	short int word = 0x0001;
	char *byte = (char *)&word;
	std::cout<<(byte[0]?"small":"big")<<std::endl;
}
void test::testAndOr()
{
	int pInt[] = {1,2,3,4,6,7};
	int n = 7;
	cout<<"缺失的数是"<<AndOr(pInt,7)<<endl;
}
void test::testAdd_no_arithm()
{
	int a = 12;
	int b = 11;
	cout<<add_no_arithm(a,b);
}
void test::testCalOneCount()
{
	cout<<calOneCount(3)<<endl;
}
void test::testCalOnCount1()
{
	cout<<calOneCount1(3)<<endl;
}
void test::testSwapOddEvenBits()
{
	int a = 5;
	cout<<"a = "<<a<<" after swap "<<swapOddEvenBits(a);
}
void test::testUpdateBits()
{
	int a = 1024;
	int b = 21;
	cout<<updateBits(a,b,2,6);
}
void test::testChinese()
{
	char p[] = "你ABCabc好";
	Chinese(p);
	cout<<p<<endl;
}
/************************************************************************/
/* 测试=运算符是否正确
*/
/************************************************************************/
void test::testMyString()
{
	printf("Test 1 Begin:\n");
	char * text = "Hello World";
	MyString str1(text);
	MyString str2;
	str2= str1;
	printf("Expect value is:%s\n",text);
	printf("Acatual value is:");
	str2.print();

}
void test::testMyString1()
{
	printf("Test 2 Begin:\n");
	char *text = "Hello World";
	MyString str1(text);
	str1 = str1;
	printf("Expect value is:%s\n",text);
	printf("Actual value is:");
	str1.print();
}
void test::testMyString2()
{
	printf("Test  Begin:\n");
	char *text = "Hello World";
	MyString str1(text);
	MyString str2,str3;
	str3 = str2 = str1;
	printf("Expect value is:%s\n",text);
	printf("str1 Actual value is:");
	str2.print();
	printf("str2 Actual value is:");
	str3.print();
}
/************************************************************************/
/* 测试有一个或者多个重复的数据                                                                     */
/************************************************************************/
void test::testDuplication()
{
	printf("Test1 Begin:\n");
	int numbers[] = {2,3,1,0,2,5,3};
	int n = sizeof(numbers)/sizeof(int);
	int number = -1;
	bool result = false;
	result = duplicate(numbers,n,&number);
	printf("Expect value is:true,The duplication number is : 2,3\n");
	printf("Actual value is:%d,The duplication number is %d\n",result,number);
}
/************************************************************************/
/* 测试不包含重复数字                                                                     */
/************************************************************************/
void test::testDuplication1()
{
	printf("Test2 Begin:\n");
	int numbers[] = {0,1,2,3,4,5,6,7};
	int length = sizeof(numbers)/sizeof(int);
	bool result = false;
	int duplication = -1;
	printf("Expect result is:false,duplication is -1\n");
	printf("Actual result is :%d,duplitain is %d\n",result,duplication);
	
}/************************************************************************/
/* 测试无效输入测试用例                                                                     */
/************************************************************************/
void test::testDuplication2()
{
	printf("Test3 Begin:\n");
	int * number = nullptr;
	int length = 10;
	bool result = false;
	int duplication = -1;
	printf("Actual result is:%d,duplication is %d\n",result,duplication);
}
/************************************************************************/
/* 测试快速排序算法是否正确                                                                     */
/************************************************************************/
void test::testQuickSort()
{
	printf("Test begin:\n");
	int a[] = {6,2,4,1,5,9};
	int size = sizeof(a)/sizeof(int);
	printf("Expect result:\n");
	for(int i = 0;i < size;++i)
		cout<<a[i]<<" ";
	cout<<endl;
	printf("Actual value:\n");
	quickSort(a,0,size-1);
	for (int i = 0;i < size;++i)
		cout<<a[i]<<" ";
	cout<<endl;
}
void test::testQuickSort1()
{
	printf("Test1 begin:\n");
	int a[] = {6,2,4,1,5,9};
	int size = sizeof(a)/sizeof(int);
	printf("Expect result:\n");
	for(int i = 0;i < size;++i)
		cout<<a[i]<<" ";
	cout<<endl;
	printf("Actual value:\n");
	quickSort(a,size,0,size -1);
	for (int i = 0;i < size;++i)
		cout<<a[i]<<" ";
	cout<<endl;
}
void test::testQuickSort2()
{
	printf("Test3 begin:\n");
	int a[] = {1,2,3,4,5,6};
	int size = sizeof(a)/sizeof(int);
	printf("Expect result:\n");
	for(int i = 0;i < size;++i)
		cout<<a[i]<<" ";
	cout<<endl;
	printf("Actual value:\n");
	quickSort(a, 0, size-1);
	for (int i = 0;i < size;++i)
		cout<<a[i]<<" ";
	cout<<endl;
}
/************************************************************************/
/* 输入 123.124685 3 -》   12.125    
输入  -123.124685 -》 -12.125
/************************************************************************/
void test::testRoundBit()
{
	double a;
	int bit;
	printf("输入你想四舍五入的小数:\n");
	scanf("%lf",&a);
	printf("输入你想保留的位数:\n");
	scanf("%d",&bit);
	roundBit(a,bit);
	printf("%.*lf\n",bit,a);////精度控制处的*代表读取一个int型参数并把它当做精度，即读取bit 

}
/************************************************************************/
/*                                                                      */
/************************************************************************/
//多个重复数字
void test::testGetDuplication1()
{
	int numbers[] = {2,3,5,4,3,2,6,7};
	int duplications[] = {2,3};
	int length = sizeof(numbers)/sizeof(int);
	int dupLength = sizeof(duplications)/sizeof(int);
	testGetDuplication("test1",numbers,length,duplications,dupLength);
}
//1个重复数字
void test::testGetDuplication4()
{
	int numbers[] = {3,2,1,4,4,5,6,7};
	int duplications[] = {4};
	testGetDuplication("test4",numbers,sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}
//没有重复数字
void test::testGetDuplication2()
{
	int numbers[] = {2,3,4,5,6,7,8,9};
	int duplications[] = {-1};
	int length = sizeof(numbers)/sizeof(int);
	int dupLength = sizeof(numbers)/sizeof(int);
	testGetDuplication("test2",numbers,length,duplications,dupLength);
}

void test::testGetDuplication3()
{
	int *numbers = nullptr;
	int length = sizeof(numbers)/sizeof(int);
	int duplications[] = {-1};
	int dupLength = sizeof(duplications) / sizeof(int);
	testGetDuplication("test3",numbers,length,duplications,dupLength);
	

}
void test::testGetDuplication(const char * testName,int * numbers,int length,int *duplications, int dupLength)
{
	int result = getDuplication(numbers,length);
	for (int i = 0;i < dupLength;++i)
	{
		if (result == duplications[i])
		{
			std::cout<<testName<<" passed."<<std::endl;
			return;
		}
			
	}
	std::cout<<testName<<" Failed."<<std::endl;

}

void test::testFind(const char * testName, int * matrix, int rows, int columns, int number, bool expected)
{
	bool result = Find(matrix, rows, columns, number);
	if (result == expected)
		std::cout<<testName<<" Passed."<<std::endl;
	else
		std::cout<<testName<<" Failed."<<std::endl;
}
//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void test::testFind1()
{
	int matrix[][4] = {{1, 2, 8, 9},{2, 4, 9, 12},{4, 7, 10, 13},{6, 8,11, 15}};
	testFind("test1", (int *)matrix, 4, 4, 7, true);
}
//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中

void test::testFind2()
{
	int matrix[][4] = {{1, 2, 8, 9},{2, 4, 9, 12},{4, 7, 10, 13},{6, 8,11, 15}};
	testFind("test2", (int *)matrix, 4, 4, 5, true);
}
//鲁棒性测试

void test::testFind3()
{
	testFind("test3", nullptr, 0, 0, 16, false);
}
void test::test1()
{
	int a,b;
	a = (b = 4) = 3;
	std::cout<<a<<" "<<b<<std::endl;
}
void test::testReplaceBlack(const char * testName, char *string, int length, char *afterString)
{
	std::cout<<testName<<" ";
	ReplaceBlack(string, length);
	if (!strcmp(string,afterString))
		std::cout<<"Passed. "<<std::endl;
	else
		std::cout<<"Failed. "<<std::endl;
}

void test::testReplaceBlack1()
{
	const int length  = 20;
	char  string[length] ="Hello World";
	char * afterString = "Hello%20World";
	testReplaceBlack("test1", string, length, afterString);
}

void test::testReplaceBlack2()
{
	const int length = 20;
	char  string[length] = "HelloWorld";
	char * afterString = "HelloWorld";
	testReplaceBlack("test2", string, length, afterString);
}

void test::testReplaceBlack3()
{
	const int length = 20;
	char string[length] = " HelloWorld";
	char * afterString = "%20HelloWorld";
	testReplaceBlack("test3", string, length, afterString);
}
void test::testReplaceBlack4()
{
	const int length = 20;
	char string[length] = "  HelloWorld";
	char *afterString = "%20%20HelloWorld";
	testReplaceBlack("test4", string, length, afterString);
}
void test::testList()
{
	ListNode * pHead = nullptr;
	//AddToTail(&pHead, 1);
	//AddToTail(&pHead, 2);
	//AddToTail(&pHead, 3);
	//RemoveNode(&pHead,7);
	AddToTail(&pHead,7);
	RemoveNode(&pHead,7);
	//AddToTail(&pHead,7);
	printList(pHead);
}

void test::testPrintReversingly()
{
	ListNode * pHead = new ListNode(1);
	AddToTail(&pHead,2);
	AddToTail(&pHead,3);
	AddToTail(&pHead,4);
	PrintListReversingly_Iteratively(pHead);
}

void test::testPrintReversingly1()
{
	ListNode * pHead = new ListNode(1);
	PrintListReversingly_Iteratively(pHead);
}
void test::testPrintReversingly2()
{
	ListNode * pHead = nullptr;
	PrintListReversingly_Iteratively(pHead);
}

void test::testPrintRecursively1()
{
	ListNode * pHead = new  ListNode(1);
	AddToTail(&pHead,2);
	PrintListReversingly_Recursively(pHead);
	std::cout<<std::endl;
}

void test::testPrintRecursively2()
{
	ListNode *pHead = nullptr;
	PrintListReversingly_Recursively(pHead);
	std::cout<<std::endl;
}
void test::testPrintRecursively3()
{
	ListNode *pHead = new ListNode(1);
	AddToTail(&pHead, 2);
	AddToTail(&pHead, 3);
	PrintListReversingly_Recursively(pHead);
	std::cout<<std::endl;
}
void test::testConstructTree(const char *testName, int *preorder, int *inorder, int length)
{
	if (testName != nullptr)
		std::cout<<testName<<" begin: \n";
	std::cout<<"The preorder is:";
	for(int i = 0;i < length;++i)
		std::cout<<preorder[i]<<" ";
	std::cout<<std::endl;
	std::cout<<"The inorder is:";
	for (int i = 0;i < length;++i)
		std::cout<<inorder[i]<<" ";
	std::cout<<endl;
	try
	{
		BinaryTreeNode * root = Construct(preorder, inorder, length);
		PrintTree(root);
		DestroyTree(root);
	}
	catch (std::exception exception)
	{
		std::cout<<exception.what()<<std::endl;
		
	}


}
/*
普通二叉树
*/
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void test::testConstructTree1()
{
	int preorder[] = {1,2,4,7,3,5,6,8};
	int inorder[] = {4,7,2,1,5,3,8,6};
	testConstructTree("test1", preorder, inorder, sizeof(preorder) / sizeof(int));
}
// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5

void test::testConstructTree2()
{
	int preorder[] = {1,2,3,4,5};
	int inorder[] = {5,4,3,2,1};
	testConstructTree("test2", preorder, inorder, sizeof(preorder) / sizeof(int));
}

//所有节点没有左节点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void test::testConstructTree3()
{
	int preorder[] = {1,2,3,4,5};
	int inorder[] = {1,2,3,4,5};
	testConstructTree("test3", preorder, inorder, sizeof(preorder) / sizeof(int));
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7

void test::testConstructTree4()
{
	int preorder[] = {1,2,4,5,3,6,7};
	int inorder[] = {4,2,5,1,6,3,7};
	testConstructTree("test4", preorder, inorder, sizeof(preorder) / sizeof(int));
}

//空指针
void test::testConstructTree5()
{
		testConstructTree("test5", nullptr, nullptr, 0);
}

// 输入的两个序列不匹配

void test::testConstructTree6()
{
	int preorder[] = {1,2,4,5,3,6,7};
	int inorder[] = {4,2,8,1,6,3,7};
	testConstructTree("test6", preorder, inorder, sizeof(preorder) / sizeof(int));
}

void test::testGetNextNode(const char * testName, _BinaryTreeNode *pNode, _BinaryTreeNode *expected)
{
	if ( testName != nullptr)
		std::cout<<testName<<": ";
	_BinaryTreeNode * node = GetNext(pNode);
	if ( node == expected)
		std::cout<<" Passed.\n";
	else
		std::cout<<" Failed.\n";
}
//            8
//        6      10
//       5 7    9  11
void test::testGetNextNode1()
{
	_BinaryTreeNode * pNode8 = new _BinaryTreeNode(8);
	_BinaryTreeNode * pNode6 = new _BinaryTreeNode(6);
	_BinaryTreeNode * pNode10 = new _BinaryTreeNode(10);
	_BinaryTreeNode * pNode5 = new _BinaryTreeNode(5);
	_BinaryTreeNode * pNode7 = new _BinaryTreeNode(7);
	_BinaryTreeNode * pNode9 = new _BinaryTreeNode(9);
	_BinaryTreeNode * pNode11 = new _BinaryTreeNode(11);
	ConnectBinaryTreeNode(pNode8, pNode6, pNode10);
	ConnectBinaryTreeNode(pNode6, pNode5, pNode7);
	ConnectBinaryTreeNode(pNode10, pNode9, pNode11);
	testGetNextNode("test1", pNode8, pNode9);
	testGetNextNode("test2", pNode6, pNode7);
	testGetNextNode("test3", pNode10, pNode11);
	testGetNextNode("test4", pNode9, pNode10);
	testGetNextNode("test5", pNode11, nullptr);
}
//            5
//          4
//        3
//      2
void test::testGetNextNode2()
{
	_BinaryTreeNode *pNode5 = new _BinaryTreeNode(5);
	_BinaryTreeNode *pNode4 = new _BinaryTreeNode(4);
	_BinaryTreeNode *pNode3 = new _BinaryTreeNode(3);
	_BinaryTreeNode *pNode2 = new _BinaryTreeNode(2);

	ConnectBinaryTreeNode(pNode5, pNode4, nullptr);
	ConnectBinaryTreeNode(pNode4, pNode3, nullptr);
	ConnectBinaryTreeNode(pNode3, pNode2, nullptr);

	testGetNextNode("test6", pNode5, nullptr);
	testGetNextNode("test7", pNode4, pNode5);
	testGetNextNode("test8", pNode3, pNode4);
	testGetNextNode("test9", pNode2,pNode3);
}
//        5
//         4
//          3
//           2
void test::testGetNextNode3()
{
	_BinaryTreeNode *pNode5 = new _BinaryTreeNode(5);
	_BinaryTreeNode *pNode4 = new _BinaryTreeNode(4);
	_BinaryTreeNode *pNode3 = new _BinaryTreeNode(3);
	_BinaryTreeNode *pNode2 = new _BinaryTreeNode(2);

	ConnectBinaryTreeNode(pNode5, nullptr, pNode4);
	ConnectBinaryTreeNode(pNode4, nullptr, pNode3);
	ConnectBinaryTreeNode(pNode3, nullptr, pNode2);

	testGetNextNode("test10", pNode5, pNode4);
	testGetNextNode("test11", pNode4, pNode3);
	testGetNextNode("test12", pNode3, pNode2);
	testGetNextNode("test13", pNode2,nullptr);
}

void test::testCQueue()
{
	try
	{
		CQueue<int> queue;
		cout<<queue.deleteHead()<<" ";
		queue.appendToTail(1);
		queue.appendToTail(2);
		cout<<queue.deleteHead()<<" ";
		cout<<queue.deleteHead()<<" ";
	}catch(exception e)
	{
		cout<<e.what();
	}

}
void test::testFibonacci1()
{
	cout<<Fibonacci(5)<<"\n";
}

void test::testFibonacci2()
{
	cout<<Fibonacci1(5)<<"\n";
}

void test::testMin(const char * testName, int * numbers, int length, int expected)
{
	cout<<testName<< "Begin:";
	int min = Min(numbers,length);
	if(min == expected)
		cout<<"Passed .\n";
	else 
		cout<<"Failed.\n";
}
/************************************************************************/
/* 34512                                                                     */
/************************************************************************/
void test::testMin1()
{
	int numbers[] = {3,4,5,1,2};
	int length = sizeof(numbers)/ sizeof(int);
	testMin("test1", numbers, length, 1);
}
/************************************************************************/
/* 10111 11101                                                                     */
/************************************************************************/
void test::testMin2()
{
	int numbers[] = {1,0,1,1,1};
	int length = sizeof(numbers) / sizeof(int);
	testMin("test2", numbers, length, 0);
}

void test::testMin3()
{
	int numbers[] = {1,1,1,0,1};
	int length = sizeof(numbers) / sizeof(int);
	testMin("test3", numbers, length, 0);
}

void test::testHasPath(const char * testName, char * matrix, int rows, int cols, char * str, bool expected)
{
	if (testName != nullptr)
		std::cout<<testName<<":";
	bool result = hasPath(matrix, rows, cols, str);
	if(result == expected)
		std::cout<<"Passed.\n";
	else
		std::cout<<"Failed.\n";
}

void test::testHasPath1()
{
	char  matrix[] = "abtgcfcsjdeh";
	int rows = 3,cols = 4;
	char * str = "bfce";
	char * str1 = "abfb";
	testHasPath("test1", matrix, rows, cols, str, true);
	testHasPath("test2", matrix, rows, cols, str1, false);
}

void test::testHasPath2()
{
	char matrix[] = "abtgcfcsjdeh";
	int rows = 1;
	int cols = 12;
	char * str = "tgcf";
	char * str1 = "gcfa";
	testHasPath("test3:", matrix, rows, cols, str, true);
	testHasPath("test4", matrix, rows, cols, str1, false);


}
void test::testHasPath3()
{
	try
	{
		testHasPath("test5",nullptr, 0, 0, nullptr, false);
	}catch(exception *e)
	{
		cout<<e->what()<<"\n";
	}
	
}

void test::testHasPath4()
{
	char matrix[] ="AAAAAAAAAAAA";
	char * str = "AAAA";
	int rows = 3;
	int cols = 4;
	testHasPath("test6",matrix, rows, cols, str, true);
}


void test::testMovingRobit(const char *testName,int threshold, int rows, int cols, int expected)
{
	if (testName != nullptr)
		std::cout<<testName<<" ";
	int count = moving(threshold, rows, cols);
	if (expected == count)
		std::cout<<"Passed. \n";
	else
		std::cout<<"Failed. \n";
}
// 方格多行多列
void test::testMovingRobit1()
{
	testMovingRobit("test1", 5, 10, 10, 21);//多行多列
	testMovingRobit("Test2", 15, 20, 20, 359);//多行多列
	testMovingRobit("Test3", 10, 1, 10, 10);//一行多列 全部满足
	testMovingRobit("Test4", 10, 1, 100, 29);//一行多列 部分满足
	testMovingRobit("Test5", 15, 100, 1, 79);//多行一列部分
	testMovingRobit("Test6", 15, 10, 1, 10);//多行一列全部
	testMovingRobit("Test7", 15, 1, 1, 1);//一行一列全部
	testMovingRobit("Test8", 0, 1, 1, 1);//一行一列不存在
	testMovingRobit("Test9", -10, 10, 10, 0);//不存在
}

void test::testMaxProductAfterCutting(const char * testName, int length, int expected)
{
	if(testName != nullptr)
		cout<<testName<<" ";
	int result = maxProductAfterCutting_solution(length);
	if (result == expected)
		cout<<"Passed .\n";
	else
		cout<<"Failed .\n";

}

void test::testMaxProductAfterCutting1()
{
	testMaxProductAfterCutting("test1", 4, 4);
	testMaxProductAfterCutting("test2", 5, 6);
	testMaxProductAfterCutting("test3", 6, 9);
	testMaxProductAfterCutting("test4", 7, 12);
}

void test::testMaxProductAfterCutting2(const char * testName, int length, int expected)
{
	if(testName != nullptr)
		cout<<testName<<" ";
	int result = maxProductAfterCutting_solution2(length);
	if (result == expected)
		cout<<"Passed .\n";
	else
		cout<<"Failed .\n";

}
void test::testMaxProductAfterCutting3()
{
	testMaxProductAfterCutting2("test1", 4, 4);
	testMaxProductAfterCutting2("test2", 5, 6);
	testMaxProductAfterCutting2("test3", 6, 9);
	testMaxProductAfterCutting2("test4", 7, 12);
}

void test::testPower()
{
	cout<<Power(2,3)<<"\n";
}
void test::testPrintMaxNDigit()
{
	cout<<"test1:\n";
	PrintMaxNdigit(2);
	cout<<"test2:\n";
	PrintMaxNdigit(33);
	cout<<"test3:\n";
	PrintMaxNdigit(-1);
}

void test::testPrintMaxNDigit1()
{
	cout<<"test1:\n";
	PrintMaxNdigit1(6);
}

void test::testDeleteDuplication()
{
	cout<<"test1:\n";
	ListNode * pHead = new ListNode(1);
	AddToTail(&pHead,2);
	AddToTail(&pHead,3);
	AddToTail(&pHead,3);
	AddToTail(&pHead,4);
	AddToTail(&pHead,4);
	AddToTail(&pHead,5);
	pHead = deleteDuplication(pHead);
	printList(pHead);
}
void test::testDeleteOneNode()
{
	cout<<"test1:\n";
	ListNode * pHead = new ListNode(1);
	AddToTail(&pHead,2);
	AddToTail(&pHead,3);
	AddToTail(&pHead,3);
	AddToTail(&pHead,4);
	AddToTail(&pHead,4);
	AddToTail(&pHead,5);
	DeleteNode(&pHead,pHead);
	printList(pHead);

}

void test::testMatchStr()
{
	char * str ="";
	char *pattern = ".*";
	bool result = match(str,pattern);
	cout<<result<<"\n";
}
void test::testIsNumberic()
{
	char * str = "100";
	bool result= isNumeric(str);
	cout<<result<<"\n";
}
void test::testEntryNodeOfLoop()
{
	ListNode *pHead = new ListNode(1);
	AddToTail(&pHead,2);
	ListNode * node = AddToTail(&pHead,3);
	AddToTail(&pHead,4);
	AddToTail(&pHead,5);
	ListNode * node1 = AddToTail(&pHead,6);
	node1->m_pNext = node;
	ListNode *pEntry = EntryNodeOfLoop(pHead);
	cout<<pEntry->m_nKey<<"\n";

}
void test::testReverseNode()
{
	ListNode *pHead = new ListNode(1);
	AddToTail(&pHead,2);
	AddToTail(&pHead,3);
	AddToTail(&pHead,4);
	ListNode * newHead = ReverseList(pHead);
	printList(newHead);
}

void test::testVerifyVector()
{
	int a[] = {5, 7, 6, 9, 11, 10, 8};
	vector<int> sequence(a,a+sizeof(a)/sizeof(int));
	cout<<VerifySquenceOfBST(sequence)<<"\n";
	int b[] = {7, 4, 6, 5};
	vector<int> sequence1(b, b+sizeof(b)/sizeof(int));
	cout<<VerifySquenceOfBST(sequence1)<<"\n";
}
void test::testSerializeTree()
{
	BinaryTreeNode * head1 = new BinaryTreeNode(1);
	BinaryTreeNode * node2 = new BinaryTreeNode(2);
	BinaryTreeNode * node3 = new BinaryTreeNode(3);
	BinaryTreeNode * node4 = new BinaryTreeNode(4);
	BinaryTreeNode * node5 = new BinaryTreeNode(5);
	BinaryTreeNode * node6 = new BinaryTreeNode(6);
	head1->m_pLeft = node2;
	head1->m_pRight = node3;
	node2->m_pLeft = node4;
	node3->m_pLeft = node5;
	node3->m_pRight = node6;
	char * str = Serialize(head1);
	BinaryTreeNode * newHead = Deserialize(str);
	PrintTree(newHead);
	str = Serialize(newHead);
	while(*str != '\0')
		cout<<*str++<<"\n";
	cout<<"\n";
}

void test::testSerializeTree1()
{
	BinaryTreeNode * head8 = new BinaryTreeNode(8);
	BinaryTreeNode * node6 = new BinaryTreeNode(6);
	BinaryTreeNode * node10 = new BinaryTreeNode(10);
	BinaryTreeNode * node5 = new BinaryTreeNode(5);
	BinaryTreeNode * node7 = new BinaryTreeNode(7);
	BinaryTreeNode * node9 = new BinaryTreeNode(9);
	BinaryTreeNode * node11 = new BinaryTreeNode(11);
	head8->m_pLeft = node6;
	head8->m_pRight = node10;
	node6->m_pLeft = node5;
	node6->m_pRight = node7;
	node10->m_pLeft = node9;
	node10->m_pRight = node11;
	char * str = Serialize(head8);
	char * str1 = str;
	while(*str1 != '\0')
		cout<<*str1++<<"\n";
	cout<<"\n";
	cout<<"\n";

	BinaryTreeNode * newHead = Deserialize(str);
	PrintTree(newHead);
	str = Serialize(newHead);
	while(*str != '\0')
		cout<<*str++<<"\n";
	cout<<"\n";
}

void test::testString3()
{
	string str = "abc";
	//const char *p = str.c_str();
	//const char *p1 = str.data();
    char *p2  = (char *)malloc(sizeof(char)*(str.length()+1));
	str.copy(p2,str.length(),0);
	*(p2+str.length()) = '\0';
	//char p2[10]={0};
	strcpy(p2,str.data());
	cout<<p2<<endl;
}
void test::testPermutation()
{
	char str[] = "abc";
	Permutation(str);
}

void test::testInsertSort()
{
	int a[] = {12, 15, 9, 20, 6, 31, 24};
	vector<int> a1(a,a+sizeof(a)/sizeof(int));
	Sort::InsertSort(a1);
	for (int i = 0;i < a1.size();++i)
	{

		cout<<a1[i]<<endl;
	}


}

void test::testQuickSort_()
{
	//int a[] = {12, 15, 9, 20, 6, 31, 24};
	int a[] = {6,10,10,3,7,1,8};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	Sort::quickSort(vec, 0, vec.size()-1);
	for (int i = 0;i < vec.size();++i)
		cout<<vec[i]<<endl;
}

void test::testShellSort()
{
	int a[] = {49, 38, 65, 97, 26, 13, 27, 49, 55, 4};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	Sort::shellSort(vec);
	for (int i = 0;i < vec.size();++i)
		cout<<vec[i]<<endl;
}

void test::testSimpleSelectSort()
{
	int a[] = {49, 38, 65, 97, 26, 13, 27, 49, 55, 4};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	Sort::simpleSelectSort(vec);
	for (int i = 0;i < vec.size();++i)
		cout<<vec[i]<<endl;
}

void test::testHeapSort()
{
	int a[] = {0,49, 38, 65, 97, 26, 13, 27, 49, 55, 4};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	Sort::HeapSort(vec, vec.size()-1);
	vec.push_back(12);
	Sort::AdjustUp(vec,vec.size()-1,vec.size()-1);
	for (int i = 0;i < vec.size();++i)
		cout<<vec[i]<<endl;
}

void test::testBubbleSort()
{
	int a[] = {0,49, 38, 65, 97, 26, 13, 27, 49, 55, 4};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	Sort::bubbleSort(vec);
	for (int i = 0;i < vec.size();++i)
		cout<<vec[i]<<endl;
}

void test::testMergeSort()
{
	int a[] = {0,49, 38, 65, 97, 26, 13, 27, 49, 55, 4};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	Sort::mergeSort(vec,0, vec.size()-1);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout<<*(it)<<endl;
	}

}

void test::testMergeSort1()
{
	int a[] = {0,49, 38, 65, 97, 26, 13, 27, 49, 55, 4};
	int size = sizeof(a)/sizeof(int);
	Sort::mergeSort(a, 0, size - 1);
	for (int i = 0;i < size;++i)
	{
		cout<<a[i]<<endl;
	}
}
void test::testCountSort()
{
	int a[] = {0,49, 38, 65, 97, 26, 13, 27, 49, 55, 4};
	int size = sizeof(a)/sizeof(int);
	Sort::countSort(a, size);
	for (int i = 0;i < size;++i)
	{
		cout<<a[i]<<endl;
	}

}

void test::testLSDSort()
{
	int a[] = {123, 22, 10, 4123, 1, 1, 9};
	int size = sizeof(a) / sizeof(int);
	Sort::countSort(a, size);
	printArray(a, size);
}
void test::printArray(int a[], int n)
{
	for (int i = 0;i < n;++i)
	{
		cout<<a[i]<<endl;
	}
}

void test::testBucketSort()
{
	int a[] = {29, 25, 3, 49, 9, 37, 21, 43};
	int size = sizeof(a) / sizeof(int);
	Sort::bucketSort(a, size);
	printArray(a, size);
}

void test::testBinarySearch()
{
	//int a[] = {29, 25,3, 49, 9, 37, 21, 43};
	//int a[] = {3, 21, 25, 29, 37, 43, 49};
	int a[] = {2, 2, 2, 2, 2, 2};
	vector<int> vec(a, a + sizeof(a)/sizeof(int) ); 
	int num = 2;
	cout<<Search::binarySearch(vec, num)<<endl;
}

void test::testStr()
{
	string str = "BIBS";
	for (int i = 0;i < str.length();++i)
	{
		cout<<str.substr(i)<<endl;
	}
}

void test::testSuffixTree()
{
	string testString = "MISSISSIPPI";
	string stringList[] = {"IS", "SIP","HI","SIS"};
	SuffixTree tree(testString);
	for (int i = 0;i < 4;i++)
	{
		vector<int> li = tree.getIndexes(stringList[i]);
		if (li.size() != 0)
		{
			cout<<stringList[i]<<" ";
			for (int j = 0; j < li.size(); ++j)
			{
				cout<<li[j]<<" ";
			}
			cout<<endl;
		}
	}
}

void test::testMaxStr()
{
	char str[] = "abcdabcd";
	int i = 0;
	int j = 0;
	int maxlen = maxStr(str,sizeof(str)/sizeof(char), i, j);
	cout<<maxlen<<endl;
}

void test::testSuffixArray()
{
	suffixArray();
}

void test::testBitMap()
{
	//set(1);
	//cout<<test001(1)<<endl;
}

void test::testBitset()
{
	using std::bitset;
	bitset<32> foo("110");
	cout<<foo.to_string()<<endl;
	cout<<foo.to_ullong()<<endl;
	cout<<foo.count()<<endl;
	foo.set();
	cout<<foo.to_string()<<endl;
	foo.reset(0);
	cout<<foo.to_string()<<endl;
	cout<<foo.test(1)<<endl;
}

void test::testSet()
{
	using std::set;
	int a[] = {3,3,3,5,7,9};
	int len = sizeof(a) / sizeof(int);
	vector<int> vec(a,a + sizeof(a)/sizeof(int));
	set<int> s;
	int j = 0;
	map<int, int> mp;

	for (int i = 0;i < vec.size();++i)
	{
		//cout<<mp.insert(pair<int, int>(i,vec[i])).second<<endl;
		if (!mp.insert(make_pair(i, vec[i])).second)
			j++;
	}
	cout<<j<<endl;
}

void test::testSolution4()
{
	Solution5 s;
	vector<vector<int> > gifts(4, vector<int>(4, 0));
	int a[4][4] = {{1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5}};
	for (int i = 0;i < 4;++i)
	{
		for (int j = 0;j < 4;++j)
		{
			gifts[i][j] = a[i][j];
		}
	}
	cout<<s.getMaxValue(gifts)<<endl;
}

void test::testSolution5()
{
	Solution6 s;
	string str1 = "arabcacfr";
	cout<<s.getMaxLength(str1)<<endl;
}

void test::testSolution6()
{
	//Solution7 s;
	//s.getSize(2,".x.");
}

void test::testMemmove()
{
	char src[10] = "12345";
	char *dest = src+3;
	char *result = (char *)my_memcpy(dest, src, 5);
	cout<<result<<endl;
}

void test::testUsing()
{
	//template<typename T>
	//using VEC = vector<T, allocator<T>>;
	//XCLs<int, VEC> c1;
}

void test::testLambda()
{
	auto I = []{
		cout << "Hello Labbda" << endl;
	};
	I();
}

void test::test360()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> lights;

		for (int i = 0; i < n; ++i)
		{
			int k = 0;
			cin >> k;
			vector<int> temp(k, 0);
			for (int j = 0; j < k; ++j)
				cin >> temp[j];
			lights.push_back(temp);
		}
		sort(lights.begin(), lights.end(), Less());//sort实现有大到小
		for_each(lights.begin(), lights.end(), Show<vector<int>>());
	}
}

void test::testString1()
{
	string str1 = "abc";
	string str2 = "abc";

	char *str3 = "abc";
	char *str4 = "abc";

	char str5[] = "abc";
	char str6[] = "abc";
	if (str1 == str2)
		cout << "str1 == str2" << endl;
	if (str3 == str4)
		cout << "str3 == str4" << endl;
	if (str5 == str6)
		cout << "str5 == str6" << endl;
}
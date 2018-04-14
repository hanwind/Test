#pragma once
#define N 2
#include "exercise.h"
#include <iostream>
#include "List.h"
#include "NextNodeInBinary.h"
#include "SuffixTreeNode.h"
#include "structs.h"
namespace test
{
	void testRotate();
	void testCal();
	void testSmallLarge();
	void testFunction();
	void testGet_nextval();
	void testfindChildStr();
	void testStrToInt();
	void testMultiply();
	void testReverseSentence();
	void testBitOrder();
	void testAndOr();
	void testAdd_no_arithm();
	void testCalOneCount();
	void testCalOnCount1();
	void testSwapOddEvenBits();
	void testUpdateBits();
	void testChinese();
	void testMyString();
	void testMyString1();
	void testMyString2();
	void testDuplication();
	void testDuplication1();
	void testDuplication2();
	void testQuickSort();
	void testQuickSort1();
	void testQuickSort2();
	void testRoundBit();//四舍五入
	void testGetDuplication1();//P
	void testGetDuplication2();//
	void testGetDuplication3();
	void testGetDuplication4();
	void testGetDuplication(const char * testName,int * numbers,int length,int *duplications, int duplength);
	void testFind(const char * testName, int * matrix, int rows, int columns, int number, bool expected);
	void testFind1();
	void testFind2();
	void testFind3();
	void test1();
	void testReplaceBlack(const char *testName, char * string, int length, char * afterString);
	void testReplaceBlack1();
	void testReplaceBlack2();
	void testReplaceBlack3();
	void testReplaceBlack4();
	void testList();
	void testPrintReversingly();
	void testPrintReversingly1();
	void testPrintReversingly2();
	void testPrintRecursively1();
	void testPrintRecursively2();
	void testPrintRecursively3();
	void testConstructTree(const char *testName, int *preorder, int *inorder, int length);
	void testConstructTree1();
	void testConstructTree2();
	void testConstructTree3();
	void testConstructTree4();
	void testConstructTree5();
	void testConstructTree6();
	void testGetNextNode(const char * testName, _BinaryTreeNode *pNode, _BinaryTreeNode *expected);
	void testGetNextNode1();
	void testGetNextNode2();
	void testGetNextNode3();
	void testCQueue();
	void testFibonacci1();
	void testFibonacci2();
	void testMin(const char * testName, int * numbers, int length, int expected);
	void testMin1();
	void testMin2();
	void testMin3();
	void testMin4();
	void testHasPath(const char * testName, char * matrix, int rows, int cols, char * str, bool expected);
	void testHasPath1();//功能测试
	void testHasPath2();//边界测试
	void testHasPath3();//特殊输入
	void testHasPath4();
	void testMovingRobit(const char *testName,int threshold, int rows, int cols, int expected);
	void testMovingRobit1();
	void testMaxProductAfterCutting(const char * testName, int length, int expected);
	void testMaxProductAfterCutting1();
	void testMaxProductAfterCutting3();
	void testMaxProductAfterCutting2(const char * testName, int length, int expected);
	void testPower();
	void testPrintMaxNDigit();
	void testPrintMaxNDigit1();
	void testDeleteDuplication();
	void testDeleteOneNode();
	void testMatchStr();
	void testIsNumberic();
	void testEntryNodeOfLoop();
	void testReverseNode();
	void testVerifyVector();
	void testSerializeTree();
	void testSerializeTree1();
	void testString3();
	void testPermutation();
	void testInsertSort();
	void testQuickSort_();
	void testShellSort();
	void testSimpleSelectSort();
	void testHeapSort();
	void testBubbleSort();
	void testMergeSort();
	void testMergeSort1();
	void testCountSort();
	void testLSDSort();
	void printArray(int a[], int n);
	void testBucketSort();
	void testBinarySearch();
	void testStr();
	void testSuffixTree();
	void testMaxStr();
	void testSuffixArray();
	void testBitMap();
	void testBitset();//测试bitset模板类
	void testSet();
	void testSolution4();
	void testSolution5();
	void testSolution6();
	void testMemmove();

	//C++11的新特性
	void testUsing();
	void testLambda();

	//360笔试题
	void test360();

	void testString1();
}


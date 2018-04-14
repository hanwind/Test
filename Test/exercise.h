#pragma once
#define N 2
#include <assert.h>
#include <vector>
#include "List.h"
enum Status{kValid,KInvalid};
using namespace std;
//将一个N*N的矩阵顺时针旋转90度
void rotate(int matrix[][N]);
//王道程序员 P19-15
int *cal(int *input,int n);
int *cal1(int *input,int n);
void smallLarge(int *arr,int *rightMin,int n);
int function(int data[],int length);
int kmp(const char * src,int slen,const char *path,int plen,const int *nextval,int pos);
void get_nextval(char const *ptrn,int plen,int *nextval);
bool findChildStr(const char *const src,const char *const des);
int strToInt(const char *str);
//大数相乘
void multiply(const char * a,const char *b);
void Reverse(char * pb,char *pe);
char * ReverseSentence(char *pData);
int AndOr(int *pInt,int n);
int add_no_arithm(int a,int b);
int calOneCount(unsigned int n);
int calOneCount1(unsigned int n);
int swapOddEvenBits(int x);
int updateBits(int n,int m ,int i,int j);
void Chinese(char * szWord);
bool duplicate(int numbers[],int length,int *duplication);
void quickSort(int *data,int low,int high);
int partition(int *data,int low,int high);
int partition(int *data, int length, int start, int end);//P 剑指80
void quickSort(int *data, int length, int start, int end);
void swap(int &a, int &b);
int RandomInRange(int start, int end);
double roundBit(double a,int bit);
int getDuplication(const int *numbers, int length); 
int countRange(const int * numbers, int lenght, int start, int end);//数组属于[start,end]区里内的个数
bool Find(int *matrix,int rows, int columns, int numbers);
void ReplaceBlack(char string[], int length);
void PrintListReversingly_Iteratively(ListNode * pHead);
void PrintListReversingly_Recursively(ListNode * pHead);
long long Fibonacci(unsigned n);
long long Fibonacci1(unsigned n);
int Min(int * numbers,int length);//P85
int MinOrder(int *data, int low, int high);
bool hasPath(char *matrix,int rows, int cols, char *str);
bool hasPathCore(char *matrix,bool * visited,int rows, int cols, int row, int col, int &strLength,char *str);
int moving(int threshold, int rows,int cols);
int movingCountCore(int threshold,bool * visited, int rows, int cols, int row, int col);
bool check(int threhold, int rows, int cols,int row, int col, bool * visited);
int getDigitSum(int number);
int maxProductAfterCutting_solution(int length);
int maxProductAfterCutting_solution2(int length);
int counNumberOne(int n);
double Power(double base, int exponent);
double PowerCore(double base, int exponent);
bool equal(double a, double b);
void PrintMaxNdigit(int n);
bool Increment(char *number, int n);//当数字不是最大的时候
void PrintDigit(char *number);
void PrintMaxNdigitRecursively(char *number, int length, int index);
void PrintMaxNdigit1(int length);
bool match(char* str, char* pattern);
bool matchCore(char * str, char * pattern);
bool isNumeric(char* string);
bool isInt(char ** string);
bool isUnsignInt(char ** string);
ListNode* EntryNodeOfLoop(ListNode* pHead);
ListNode* ReverseList(ListNode* pHead);
bool VerifySquenceOfBST(vector<int> &sequence);
bool fun(int begin, int end, vector<int> &sequence);
void Permutation(char *str);
void Permutation(char *pStr, char * pBegin,int & number);

//查找最大重复子串
int maxStr(char *str,int n, int &low, int &high);
int comlen(char *p, char *q);
void suffixArray();
int pstrcmp(const void *p1, const void *p2);

//字符串的copy
void * my_memcpy(void * dest, const void * src, int n);
void *my_memmove(void *dest, const void *src, int n);
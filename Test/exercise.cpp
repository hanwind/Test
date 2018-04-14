#include "exercise.h"
#include <exception>
#include <iostream>
#include <stack>
#include "Fibonacci.h"
void rotate(int matrix[][N])
{
	for (int layer = 0;layer <N/2;++layer)
	{
		int first = layer;
		int last = N -1 -layer;
		for (int i = first;i < last;++i)
		{
			int offset = i - first;
			int top = matrix[first][i];
			matrix[first][i] = matrix[last-offset][first];
			matrix[last-offset][first] = matrix[last][last-offset];
			matrix[last][last-offset] = matrix[i][last];
			matrix[i][last] = top;
		}
	}
}

int *cal(int *input,int n)
{
	int *left = new int[n];
	int *right = new int[n];
	int *result = new int[n];
	left[0] = 1;
	right[n-1] = 1;
	for (int i = 1;i < n;++i)
	{
		left[i] = left[i-1]*input[i-1];
	}

	for (int i = n-2;i >=0;i--)
	{
		right[i] = input[i+1]*right[i+1];
	}
	for (int i = 0;i < n;++i)
	{
		result[i] = left[i]*right[i];
	}
	return result;
}
int *cal1(int *input,int n)
{
	int i;
	int *result = new int[n];
	result[0] = 1;
	for (i = 1;i < n;++i)
		result[i] = result[i]*input[i];
	result[0] = input[n-1];
	for (i = n-2;i>0;--i)
	{
		result[i] *= result[0];
		result[0] *= input[i];
	}
	return result;
}
void smallLarge(int *arr,int *rightMin,int n)
{
	int i,leftMax;
	rightMin[n-1] = arr[n-1];
	for (i = n-2;i >= 0;--i)
	{
		if (arr[i] < rightMin[i+1])
			rightMin[i] = arr[i];
		else
			rightMin[i] = rightMin[i+1];
	}

	leftMax = INT_MIN;
	for (i = 0;i < n;++i)
	{
		if (arr[i] >= leftMax)
		{
			leftMax = arr[i];
			if (leftMax == rightMin[i])
			{
				std::cout<<leftMax<<std::endl;
			}
		}
	}


}
int function(int data[],int length)
{
	int currentNum = 0;
	int currentAxis;
	for (int i = 0;i < length;++i)
	{
		if (currentNum == 0)
		{
			currentAxis = data[i];
			currentNum = 1;
		}else
		{
			if (currentAxis == data[i])
				currentNum++;
			else
				currentNum--;
		}

	}
	if(currentNum == 0)
	{
		std::cout<<"no number"<<std::endl;
	}
	return currentAxis;
}
int kmp(const char* src,int slen,const char *path,int plen,const int *nextval,int pos)
{
	int i = pos,j = 0;
	while (i < slen && j < plen)
	{
		if (j == -1 || src[i] == path[j])
		{
			i++;
			j++;
		}
		else
			j = nextval[j];
	}
	if (j >= plen)
		return i - plen;
	return -1;
}
void get_nextval(char const *ptrn,int plen,int *nextval)
{
	int j = 0;//模式串当前位置
	nextval[0] = -1;
	int k = -1;//表示匹配的最大长度
	while(j < plen-1)
	{
		if (k == -1 || ptrn[j] == ptrn[k])
		{
			k++;
			j++;
			if (ptrn[k] != ptrn[j])
			{
				nextval[j] = k;
			}else
				nextval[j] = nextval[k];
		}else
			k = nextval[k];

	}
}
//判读des是src的循环子串如：des为AABCD ->其中一个循环子串为CDAA
bool findChildStr(const char *const src,const char *const des)
{
	assert(src != NULL && des != NULL);
	int lensrc = strlen(src);
	int lendes = strlen(des);
	if (lensrc < lendes)
		return false;
	int k;
	for (int i = 0;i < lensrc;++i)
	{
		k = i;
		for (int j = 0;j < lendes;++j)
		{
			if (src[k++%lensrc] != des[j])//你假如第一个都不匹配de话，后面就不看了
			 break;
		}
		if (k - i == lendes)
			return true;
	}
	return false;

}
int strToInt(const char *str)
{
	int g_nStatus = kValid;
	g_nStatus = KInvalid;
	long long num = 0;
	bool minus = false;//Key 1:整数有正负
	if (str != NULL)
	{
		const char *digit = str;
		if (*digit == '+')
		{
			digit++;
		}else if (*digit == '-')
		{
			digit++;
			minus = true;
		}
		while (*digit != NULL)
		{
			if (*digit >= '0' && *digit <= '9')
			{
				num = num*10 + (*digit-'0');
				if (num > std::numeric_limits<int>::max())//Key 2:溢出
				{
					num = 0;
					break;
				}
				++digit;
			}else
			{
				num = 0;
				break;
			}
			if (*digit == '\0')
			{
				g_nStatus = kValid;
				if (minus)
				{
					num = 0 - num;
				}
			}	
			
		}//while
		

	}//if
	return (int)num;
}
void multiply(const char * a,const char *b)
{
	assert(a != NULL && b != NULL);
	int lena,lenb,i,j,*s;
	lena = strlen(a);
	lenb = strlen(b);
	s = (int *)malloc(sizeof(int)*(lena+lenb));
	memset(s,0,(lena+lenb)*sizeof(int));
	for (i = 0;i < lena;++i)
		for (j = 0;j < lenb;++j)
			s[i+j+1] += (a[i]-'0')*(b[j] - '0');
	//进位
	for (i = lena+lenb-1;i >= 0;--i)
	{
		if (s[i] >= 10)
		{
			s[i-1] += s[i]/10;
			s[i] %= 10;
		}
	}
	//去除首字母是0的
	i = 0;
	while (s[i] == 0) i++;
	//将结果转换为字符串输出
	char *c = (char *)malloc(sizeof(char)*(lena+lenb));
	for(j = 0;i < lena+lenb;++i,++j)
	{
		c[j] = s[i]+'0';
	}
	c[j] = '\0';
	std::cout<<c<<std::endl;
}
void Reverse(char * pb,char *pe)
{
	char temp;
	if (pb == NULL || pe == NULL) return;
	while (pb < pe)
	{
		temp = *pb;
		*pb = *pe;
		*pe = temp;
		pb++,pe--;
	}
}
char * ReverseSentence(char *pData)
{
	if (pData == NULL) return NULL;
	char  *pBgin = pData;
	char *pEnd = pData;
	pEnd += strlen(pBgin)-1;//从最后一个字符开始
	Reverse(pBgin,pEnd);//将一个字符串逆转
	pEnd = pData;
	while (*pBgin != '\0')
	{
		if (*pBgin == ' ')
		{
			pBgin++;
			pEnd++;
			continue;
		} 
		else if (*pEnd == ' ' || *pEnd == '\0')//每遇到一个单词，逆转一次
		{
			Reverse(pBgin,--pEnd);
			pBgin = ++pEnd;

		}else
		   pEnd++;
	}
	return pData;
}
//求1-n缺失的那个数
int AndOr(int *pInt,int n)
{
	assert(n > 1 || pInt != NULL);
	int temp = 0;
	for (int i = 1;i <= n;++i)
		temp ^= i; 
	for (int i = 0;i < n-1;++i)
		temp^=pInt[i];
	return temp;
}
int add_no_arithm(int a,int b)
{
	if (b == 0)
		return a;//没有进位
	int sum = a^b;//不考虑进位
	int carry = (a&b)<<1;//进位一位
	return add_no_arithm(sum,carry);
}
int calOneCount(unsigned int n)
{
	int count = 0;
	while (n > 0)
	{
		n &= n-1;
		count++;
	}
	return count;

}
int calOneCount1(unsigned int n)
{
	int count = 0;
	while (n)
	{
		if (n&1)//看最低位是不是1
			count++;
		n >>= 1;
	}
	return count;
}
int swapOddEvenBits(int x)
{
	return ((x & 0xaaaaaaaa)>>1) | ((x&0x55555555)<<1);
}
int updateBits(int n,int m ,int i,int j)
{	int max = ~0;
	int left = max - (((1<<j)+1)-1);
	int right = (1<<i)-1;
	int mask = left | right;
	return (n & mask) | (m<<i);
}
void Chinese(char * szWord)
{
	if (szWord == NULL) return;
	for (char *piterator = szWord;*piterator != 0;++piterator)
	{
		if (((*piterator)&0x80)!= 0 )//如果是汉子则跳过
		{
			++piterator;
		}else if (*piterator >= 'A' && *piterator <= 'Z')
		{
			*piterator += 32; 
		}
	}
}
/************************************************************************/
/* p39 面试题3 找出数组重复的数字                                                                     */
/************************************************************************/
bool duplicate(int numbers[],int length,int *duplication)
{
	if (numbers == nullptr || length < 0)
	{
		return false;
	}
	for (int i = 0;i < length;++i)
		if (numbers[i] < 0 || numbers[i] > length-1)
			return false;
	for (int i = 0;i < length;++i)
	{
		while(numbers[i] != i)
		{
			if ( numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[numbers[i]];
			numbers[numbers[i]] = temp;
		}
	}
	return false;

}
int partition(int *data,int low,int high)
{ 
	 int t = 0;
	 t = data[low]; 
     while(low < high)
	 {
		 while(low < high && data[high] >= t)
			high--;
		  data[low] = data[high];
		  while(low < high && data[low] <= t)
			low++;
		    data[high] = data[low];

	  }
		data[low] = t;
		return low;
}

void quickSort(int *data,int low,int high) //快排每趟进行时的枢轴要重新确定，由此进 //一步确定每个待排小记录的low及high的值
{
	if(low >= high)
		return ;
    int pivotloc = 0;
	pivotloc = partition(data,low,high);
	quickSort(data,low,pivotloc-1);
	quickSort(data,pivotloc+1,high);
}
int RandomInRange(int start, int end)
{
	return (rand() % (end - start)) + start;
}
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int partition(int *data, int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
		throw std::exception("Invalid paramter");
	int index = RandomInRange(start,end);
	int small = start -1;
	for (index = start;index < end;++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				swap(data[index],data[small]);
		}
	}
	++small;
	swap(data[small], data[end]);
	return small;
}
void quickSort(int *data, int length, int start, int end)
{
	if(start == end)
		return;
	int index = partition(data,length,start,end);
	if (index > start)
		quickSort(data,length,start,index - 1);
	if (index < end)
		quickSort(data,length, index + 1, end);

}
double roundBit(double a,int bit)
{
	if (a > 0)
	{
		a= int(a*pow(double(10),double(bit))+0.5)/pow(double(10),double(bit))/1.0;
	}
	else
	{
		a = int(a*pow(double(10),double(bit))-0.5)/pow(double(10),double(bit))/1.0;
	}
	return a;
}
int getDuplication(const int *numbers, int length)
{
	if (numbers == nullptr || length <=0)
		return -1;
	int start = 1;
	int end = length -1;
	while(end >= start)
	{
		int middle = ((end-start)>>1)+start;
		int count = countRange(numbers,length,start,middle);
		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}
		if (count > (middle - start) +1)
			end = middle;
		else
			start = middle +1;

	}
	return -1;
}

int countRange(const int * numbers, int lenght, int start, int end)
{
	if (numbers == nullptr)
		return 0;
	int count = 0;
	for (int i = 0;i < lenght;++i)
		if (numbers[i] >= start && numbers[i] <= end)
			count++;
	return count;
}
bool Find(int *matrix,int rows, int columns, int numbers)
{
	if (matrix != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while(row < rows && columns >= 0)
		{
			if (numbers == matrix[row * columns + column])
				return true;
			else if (numbers > matrix[row * columns + column])
				row++;
			else 
				column--;
		}
		return false;
	}
	return false;
}
void ReplaceBlack(char string[], int length)
{
	if (string == nullptr || length <= 0)
		return;
	int actualLength = 0;
	char * p2 = string;
	char * p1 = string;
	int count = 0;
	//计算替换后的字符串长度
	while(*p1)
		if (*p1++ == ' ')
		{
			count++;
		}
	actualLength = p1 - string;
	p1 = string + actualLength;
	p2 = p1 + count * 2;
	while(p1 >= string && p2 >= string)
	{
		if (*p1 == ' ')
		{
			*p2-- = '0';
			*p2-- = '2';
			*p2-- = '%';
			 if (p1 == p2)
				 return;
			p1--;
		}else
		{
			*p2 -- = *p1--;
		}

	}
}
/************************************************************************/
/* 反向打印链表                                                                     */
/************************************************************************/
void PrintListReversingly_Iteratively(ListNode * pHead)
{
	std::stack<ListNode *> temp;
	ListNode *pNode = pHead;
	while(pNode)
	{
		temp.push(pNode);
		pNode = pNode->m_pNext;
	}
	while(!temp.empty())
	{
		pNode = temp.top();
		temp.pop();
		std::cout<<pNode->m_nKey<<"\t";
	}
	std::cout<<std::endl;
}
void PrintListReversingly_Recursively(ListNode * pHead)
{
	if (pHead == nullptr)
		return;
	else 
	{
		PrintListReversingly_Recursively(pHead->m_pNext);
		std::cout<<pHead->m_nKey<<"\t";
	}

}
long long Fibonacci(unsigned n)
{
	assert(n > 0);
	int result[2] ={0,1};
	int fibN = 0;
	int fibOne = 0;
	int fibTwo = 1;
	if (n < 2)
		return result[n];
	for (unsigned i = 2; i <= n;++i)
	{
		fibN = fibOne + fibTwo;
		fibOne =fibTwo;
		fibTwo = fibN;
	}
	return fibN;
}

long long Fibonacci1(unsigned n)
{
	assert(n > 0);
	int result[2] = {0,1};
	if (n < 2)
		return result[n];
	return MatrixPower(n-1).m_00;

}

int Min(int *numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		throw std::exception("Invalid paramter");
	int low = 0;
	int high = length -1;
	int min = low;
	while(numbers[low] >= numbers[high])//如果直接就是有序的 while 就不成立，直接返回数组第一个值就是最小值
	{
		if ((high - low) == 1)
			break;
		min = (low + high) / 2;
		if (numbers[low] == numbers[high] &&numbers[low] == numbers[min])
			return MinOrder(numbers,low,high);
		if(numbers[min] >= numbers[low])
			low = min;
		else if (numbers[min] <= numbers[high])
			high = min;
	}
	return numbers[min];
}
int MinOrder(int *data, int low, int high)
{
	int min = low;
	for (int i =low + 1;i <= high;++i)
	{
		if (data[i] < data[min])
			min = i;
	}
	return data[min];
}

bool hasPath(char *matrix,int rows, int cols, char *str)
{
	if (matrix == NULL || str == nullptr || rows <= 0 || cols <= 0)
		throw new std::exception("Invalid parameter");
	bool * visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);//置为0
	int strLength = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0;j < cols; ++j)
		{
			if (hasPathCore(matrix, visited, rows, cols, i, j, strLength, str))
				return true;
		}
	}
	delete [] visited;
	return false;
}

bool hasPathCore(char *matrix,bool * visited,int rows, int cols, int row, int col, int &strLength,char *str)
{
	if (str[strLength] == '\0')
		return true;
	bool hasPath = false;
	if (row < rows && col < cols && row >= 0 && col >= 0 && str != nullptr && visited[row * cols + col] == false && matrix[row * cols + col] == str[strLength])
	{
		strLength++;
		visited[row * cols + col] = true;
		hasPath = hasPathCore(matrix, visited, rows, cols, row, col-1, strLength,str) || hasPathCore(matrix, visited, rows, cols, row, col+1, strLength,str)
		      ||  hasPathCore(matrix, visited, rows, cols, row-1, col, strLength,str) || hasPathCore(matrix, visited, rows, cols, row+1, col, strLength,str);
		if (!hasPath)
		{
			strLength--;
			visited[row * cols + col] = false;
		}
	}
	return hasPath;
}

int moving(int threshold, int rows,int cols)
{

	if (threshold < 0 || rows <= 0 || cols <= 0)
		return 0;
	bool * visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);
	int count = 0;
	count = movingCountCore(threshold,visited, rows, cols, 0, 0);
	delete[] visited;
	return count;
}
int movingCountCore(int threshold,bool * visited, int rows, int cols, int row, int col)
{
	int count = 0;
	if (check(threshold, rows, cols, row, col, visited))//满不满足条件
	{
		visited[row * cols + col] = true;
		count = 1 +  movingCountCore(threshold, visited,rows, cols, row, col - 1) + 
				 movingCountCore(threshold, visited,rows, cols, row, col + 1) +
				 movingCountCore(threshold, visited,rows, cols, row + 1, col) +
				 movingCountCore(threshold, visited,rows, cols, row - 1,  col);
	}
	return count;

}


bool check(int threhold, int rows, int cols, int row, int col, bool * visited)
{
	if ((row >=0) && (col >= 0) && (row < rows) & (col < cols)  && !visited[cols * row + col] && getDigitSum(row) + getDigitSum(col) <= threhold)
		return true;
	return false;
}
int getDigitSum(int number)
{
	int sum = 0;
	while(number)
	{
		sum += number  % 10;
		number /= 10; 
	}
	return sum;
}

int maxProductAfterCutting_solution(const int length)
{
	if (length <=1 )
		return 0;
	if (length == 2)
		return 1;
	if(length == 3)
		return 2;
	int * product = new int[length+1];
	product[0] = 0;
	product[1] = 1;
	product[2] = 2;
	product[3] = 3;
	int max = 0;
	int temp = 0;
	for (int i = 4;i <= length; ++i)
	{
		max = 0;
		for (int j = 1;j <= i/2; ++j)
		{
			temp = product[j] * product[i - j];
			if (max < temp)
				max = temp;
		}
		product[i] = max;
	}
	max = product[length];
	delete product;
	return max;
}

int maxProductAfterCutting_solution2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if(length == 3)
		return 2;
	int timesOf3 = length / 3;
	if ((length - timesOf3 * 3) == 1)
		timesOf3 --;
	int timesOf2 = length / 2;
	return ((int)pow((double)3, timesOf3)) * ((int)pow((double)2, timesOf2));
}

int counNumberOne(int n)
{
	int count = 0;
	while(n)
	{
		count++;
		n = (n-1) & n;
	}
	return n;
}

double Power(double base, int exponent) {
	if(equal(base,0.0) && exponent < 0) //避免出现0 的-1次方
		return 0.0;
	bool isminus = false;
	if(exponent < 0)
	{
		isminus = true;
		exponent = - exponent;
	}
	double result = PowerCore(base, exponent);
	if(isminus)
		return  double(1)/result;
	return result;
}
double PowerCore(double base, int exponent)
{
	if(exponent == 0)
		return 1.0;
	if(exponent == 1)
		return base;
	double result = PowerCore(base,exponent >> 1);
	result *= result;
	if((exponent & 0x1) == 1)
		result *= base;
	return result;
}
bool equal(double a, double b)
{
	if((a - b) < 0.0000001 && (a - b) > -0.000000001)
		return true;
	else
		return false;
}

void PrintMaxNdigit(int n)
{
	if (n <= 0)
		return;
	char * number = new char[n+1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!Increment(number, n))
	{
		PrintDigit(number);
	}
	delete[] number;
}

bool Increment(char *number, int n)//当数字不是最大的时候
{
	bool isOverFlow = false;
	if(number == nullptr)
		return false;
	int add = 1;
	for (int i = n-1;i >= 0;i--)
	{
		int digit = number[i] - '0' + add;
		if (digit >= 10)
		{
			if (i == 0)
				isOverFlow = true;
			number[i] = digit % 10 + '0';
			add = 1;
		}else
		{
			number[i] = digit + '0';
			add = 0;
			break;
		}
	}
	return isOverFlow;

}
void PrintDigit(char *number)
{
	if (number == nullptr)
		return;
	int i = 0;
	bool isBegin = false;
	while(number[i] != '\0')
	{
		if (number[i] != '0' && isBegin == false)
		{
			isBegin = true;
		}
		if (isBegin)
			std::cout<<number[i];
		i++;
	}
	std::cout<<"\n";
}
void PrintMaxNdigit1(int length)
{
	if(length <= 0)
		return;
	char *number = new char[length + 1];
	int index = 0;
	number[length] = '\0';
	for (int i = 0;i <= 9;++i)
	{
		number[index] = '0'+i;
		PrintMaxNdigitRecursively(number, length, index+1);
	}
}
void PrintMaxNdigitRecursively(char *number, int length, int index)
{
	if(index == length)
	{
		PrintDigit(number);
		return;
	}
		
	for (int i = 0;i <= 9;++i)
	{
		number[index] = '0' + i;
		PrintMaxNdigitRecursively(number, length, index+1);
	}
}

bool match(char* str, char* pattern)
{
	if(str == nullptr || pattern == nullptr)
		return false;
	return matchCore(str,pattern);
}
bool matchCore(char * str, char * pattern)
{
	if(*str == '\0' && *pattern == '\0')
		return true;
	if(*str != '\0' && *pattern == '\0')
		return false;
	if(*(pattern+1) == '*')
	{
		if(*pattern == *str || (*pattern == '.' && *str != '\0'))
		{
			return matchCore(str + 1, pattern + 2) ||
				matchCore(str + 1, pattern) ||
				matchCore(str, pattern + 2);
		}else
			return matchCore(str, pattern + 2);

	}
	if(*pattern == *str || (*pattern == '.' && *str != '\0'))
		return matchCore(str+1,pattern+1);
	return false;
}
bool isNumeric(char* string)
{
	if(string == nullptr)
		return false;
	char *str = string;
	bool numeric = isInt(&str);

	if(*str == '.')
	{
		++str;
		numeric = isUnsignInt(&str) || numeric;
	}
	if(*str == 'e' || *str == 'E')
	{
		++str;
		numeric = isInt(&str) && numeric;
	}

	return numeric && *str == '\0';
}
bool isInt(char ** string)
{
	if(**string == '+' || **string == '-')
		++(*string);
	return isUnsignInt(string);
}
bool isUnsignInt(char ** string)
{
	char * baseStr = *string;
	while(string != nullptr && **string >= '0' && **string <= '9')
		++(*string);
	return *string > baseStr;
}
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if(pHead == nullptr)
		return nullptr;
	ListNode *before = pHead->m_pNext;
	if(before == nullptr)
		return nullptr;
	ListNode *after = before->m_pNext;
	if(after == nullptr)
		return nullptr;
	while(after != nullptr && before != nullptr)
	{
		if(after == before)
			break;
		before = before->m_pNext;
		after = after->m_pNext;
		if(after != nullptr)
			after = after->m_pNext;   
	}
	if(after->m_pNext == nullptr)
		return nullptr;
	int numNode = 1;
	while(after->m_pNext != before)
	{
		after = after->m_pNext;
		++numNode;
	}
	before = pHead;
	after = pHead;
	for(int i = 0;i < numNode;++i)
	{
		after = after->m_pNext;
	}
	while(before != after)
	{
		before = before->m_pNext;
		after = after->m_pNext;
	}
	return before;
}
ListNode* ReverseList(ListNode* pHead) 
{
	if(pHead == nullptr)
		return nullptr;
	ListNode * reverseHead = pHead;
	ListNode * pNode = pHead;
	ListNode * pPre = nullptr;

	while(pNode != nullptr)
	{
		ListNode * pNext = pNode->m_pNext;
		if(pNext == nullptr)
			reverseHead = pNode; 
		pNode->m_pNext = pPre;
		pPre = pNode;
		pNode = pNext;	  
	}
	return reverseHead;


}
bool VerifySquenceOfBST(vector<int> &sequence) {
	if(sequence.size() < 0)
		return false;
	int low = 0, high = sequence.size()-2;
	if(high <= low)
		return true;
	return fun(low, high, sequence);
}

bool fun(int begin, int end, vector<int> &sequence)
{
	if(end <= begin)
		return true;
	int low = begin, high = end;
	int root = sequence[end+1];
	bool flag = true;
	while(low <= high  && flag)
	{
		flag = false;
		if(sequence[low] < root)
		{
			low++;
			flag = true;
		}
		if(sequence[high] > root)
		{
			high--;
			flag = true;
		}
			
	}
	if(high < low)
		return fun(begin, high-1, sequence) && fun(low, end-1, sequence);
	return false;

}

void Permutation(char *str)
{
	if (str == nullptr)
		return;
	int number = 0;
	Permutation(str,str,number);
	cout<<number<<endl;
}
void Permutation(char *pStr, char * pBegin,int &number)
{
	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
		number++;
	}
		
	for (char * pCh = pBegin;(*pCh) != '\0';++pCh)
	{
		if(pCh != pBegin &&(*(pCh) == *(pCh+1)))
			continue;
		swap(*pBegin, *pCh);
		Permutation(pStr, pBegin+1,number);
		swap(*pBegin, *pCh);
	}
}

int maxStr(char *str,int n, int &low, int &high)
{
	int maxLen = 0;
	int thisLen = 0;
	for (int i = 0; i < n;++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if((thisLen = comlen(str+i, str+j)) > maxLen)
			{
				maxLen =thisLen;
				low = i;
				high = j;
			}
		}
	}
	return maxLen;
}
int comlen(char *p, char *q)
{
	int i = 0;
	while(*p && *q && (*p++ == *q++)) ++i;
	return i;
}
int pstrcmp(const void *p1, const void *p2)
{
	return strcmp(*(char **)p1, *(char **)p2);
}
void suffixArray()
{
	char *a[10];
	char c[10];
	char ch;
	int n = 0;
	int maxLen = 0;
	int thiLen = 0;
	int begin;
	printf("请输入数字");
	while ((ch = getchar()) != '\n')
	{
		a[n] = &c[n];
		c[n++] = ch;
	}
	c[n] = '\0';
	qsort(a,n, sizeof(char *), pstrcmp);
	for (int j = 0;j < n-1; ++j)
	{
		if ((thiLen = comlen(a[j],a[j+1])) > maxLen)
		{
			maxLen = thiLen;
			begin = j;
		}
	}
	cout<<maxLen<<endl;

}

void * my_memcpy(void * dest, const void * src, int n)
{
	char * _dest = (char *)dest;
	char * _src = (char *)src;
	while(n--)
		*_dest++ = *_src++;
	return dest;
}
void *my_memmove(void *dest, const void *src, int n)//是按照字节拷贝的
{
	char * _dest = (char *)dest;
	char * _src = (char *) src;
	if(_src < _dest && (_dest - _src) < n)//从后往前拷贝
	{
		_dest = _dest + n -1;
		_src = _src + n - 1;
		while(n--)
			*_dest-- = *_src--;

	}else
		my_memcpy(dest, src, n);
	return dest;

}
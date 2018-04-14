#pragma once
//p25
#include<cstring>//用于strlen strcpy等函数
#include <cstdio>
class MyString
{
public:
	MyString(char *pData = nullptr);
	MyString(const MyString &str);
	MyString & operator=(const MyString &my_string);
	~MyString();
	void print();
private:
	char * m_pData;
};


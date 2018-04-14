#include "MyClass.h"
MyString::MyString(char * pData)
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}else
	{
		m_pData = new char[strlen(pData)+1];
		strcpy(m_pData,pData);
	}

}
MyString::MyString(const MyString & str)
{
	m_pData = new char[strlen(str.m_pData)+1];
	m_pData= strcpy(m_pData,str.m_pData);
}
MyString & MyString::operator=(const MyString & str)
{
	if (this != &str)
	{
		MyString tempStr(str);
		char *pTemp = tempStr.m_pData;
		tempStr.m_pData = m_pData;
		m_pData = pTemp; 
	}
	return *this;
}
MyString::~MyString()
{
	delete [] m_pData;
}
void MyString::print()
{
	printf("%s\n",m_pData);
}
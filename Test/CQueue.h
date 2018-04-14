#pragma once
#include <stack>
#include <exception>
using std::stack;
using std::exception;
template<typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);
	void appendToTail(const T & node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};


template<typename T> CQueue<T>::CQueue(void)
{
}


template<typename T> CQueue<T>::~CQueue(void)
{
}
template<typename T> void CQueue<T>::appendToTail(const T &value)
{
	stack1.push(value);
}
template<typename T> T CQueue<T>::deleteHead()
{
	T value;
	if (!stack2.empty())
	{
		value = stack2.top();
		stack2.pop();
	}else if (!stack1.empty())
	{
		while(!stack1.empty())
		{
			value = stack1.top();
			stack1.pop();
			stack2.push(value);
		}
		value = stack2.top();
		stack2.pop();
	}
	if (stack2.size() == 0)
		throw exception("queue is empty");
	return value;

}

#include "List.h"
#include <iostream>
ListNode *AddToTail(ListNode ** pHead, int value)
{
	ListNode * pNew = new ListNode();
	pNew->m_nKey = value;
	pNew->m_pNext = nullptr;
	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}else
	{
		ListNode *pNode = *pHead;
		while (pNode->m_pNext)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
	return pNew;
}
void RemoveNode(ListNode ** pHead, int value)
{
	ListNode * pNode = *pHead;
	ListNode * delNode = nullptr;
	if ((*pHead) == nullptr)
		return;
	if ((*pHead) != nullptr && (*pHead)->m_nKey == value)
	{
		delNode = *pHead;
		*pHead = (*pHead)->m_pNext;
	}else
	{
		while(pNode->m_pNext && pNode->m_pNext->m_nKey != value)
			 pNode = pNode->m_pNext;
		if (pNode->m_pNext && pNode->m_pNext->m_nKey == value)
		{
			delNode = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if (delNode)
	{
		delete delNode;
		delNode = nullptr;
	}
	

}
void printList(ListNode *pHead)
{
	while(pHead)
	{
		std::cout<<pHead->m_nKey<<std::endl;
		pHead = pHead->m_pNext;
	}

}

ListNode* deleteDuplication(ListNode* pHead)
{
	if(pHead == nullptr)
		return nullptr;
	ListNode * pNode = pHead;
	ListNode * preNode = nullptr;
	while(pNode != nullptr)
	{
		bool isEqual = false;
		ListNode * pNext = pNode->m_pNext;
		if(pNext != nullptr && pNext->m_nKey == pNode->m_nKey)
			isEqual = true;
		if(!isEqual)
		{
			preNode = pNode;
			pNode = pNext;
		}else
		{
			int value = pNode->m_nKey;
			ListNode * delNode = pNode;
			while(delNode != nullptr && delNode->m_nKey == value)
			{
				pNode = pNode->m_pNext;
				delete delNode;
				delNode = pNode;
			}
			if(preNode == nullptr)
				pHead = pNode;
			else
				preNode->m_pNext = pNode;
		}
	}
	return pHead;
}

void DeleteNode(ListNode ** pHead,ListNode *delNode)
{
	if (*pHead == nullptr || delNode == nullptr)
		return;
	if (delNode == *pHead)
	{
		*pHead = delNode->m_pNext;
		delete delNode;
		delNode = nullptr;
		return;
	}else if (delNode->m_pNext != nullptr)
	{
		ListNode * pNode = delNode;
		delNode = pNode->m_pNext;
		pNode->m_nKey = delNode->m_nKey;
		pNode->m_pNext = delNode->m_pNext;
		delete delNode;
		delNode = nullptr;
		return;
	}
	if (delNode->m_pNext == nullptr)//Î²½Úµã
	{
		ListNode * pNode = *pHead;
		while (pNode)
		{
			if (pNode->m_pNext == delNode)
			{
				pNode->m_pNext = nullptr;
				delete delNode;
				delNode = nullptr;
			}

		}
	}

}
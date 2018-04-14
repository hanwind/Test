#pragma once
struct ListNode
{
	int m_nKey;
	ListNode * m_pNext;
	ListNode(){}
	ListNode(int _m_nkey,ListNode * _next = nullptr):m_nKey(_m_nkey),m_pNext(_next){}
};
ListNode* AddToTail(ListNode ** pHead, int value);
void RemoveNode(ListNode ** pHead, int value);
void printList(ListNode *pHead);
ListNode* deleteDuplication(ListNode* pHead);
void DeleteNode(ListNode ** pHead,ListNode *delNode);
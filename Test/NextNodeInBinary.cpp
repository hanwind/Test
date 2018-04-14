#include "NextNodeInBinary.h"
#include <iostream>
_BinaryTreeNode * CreateBinaryTreeNode(int value)
{
	_BinaryTreeNode * node = new _BinaryTreeNode();
	node->m_nValue = value;
	node->m_pLeft = node->m_pRight = nullptr;
	return node;
}
void ConnectBinaryTreeNode(_BinaryTreeNode * pParent, _BinaryTreeNode * pLeft, _BinaryTreeNode * pRight)
{
	if (pParent != nullptr)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
		if (pLeft != nullptr)
			pLeft->m_pParent = pParent;
		if(pRight != nullptr)
			pRight->m_pParent = pParent;
	}
}

void PrintTreeNode(const _BinaryTreeNode *pNode)
{
	if (pNode != nullptr)
	{
		std::cout<<"value of this node is "<<pNode->m_nValue<<"\n";
		if (pNode->m_pLeft != NULL)
			std::cout<<"value of its left child is "<<pNode->m_pLeft->m_nValue<<"\n";
		else
			std::cout<<"left child is nullptr\n";
		if (pNode->m_pRight != nullptr)
			std::cout<<"value of its right child is "<<pNode->m_pRight->m_nValue<<"\n";
		else
			std::cout<<"right child is nullptr\n";
	}else
	{
		std::cout<<"this node is nullptr.\n";
	}
	
}
void PrintTree(const _BinaryTreeNode *pRoot)
{
	PrintTreeNode(pRoot);
	if (pRoot != nullptr)
	{
		if (pRoot != nullptr)
			PrintTreeNode(pRoot->m_pLeft);
		if (pRoot != nullptr)
			PrintTreeNode(pRoot->m_pRight);

	}
}
_BinaryTreeNode *GetNext(_BinaryTreeNode *node)
{
	if (node == nullptr)
		return nullptr;
	_BinaryTreeNode *pNext = nullptr;
	if (node->m_pRight != nullptr)//存在右子树
	{
		
		_BinaryTreeNode *pRight = node->m_pRight;
		while(pRight != nullptr && pRight->m_pLeft != nullptr)
			pRight = pRight->m_pLeft;

		pNext = pRight;
	}else
	{
		_BinaryTreeNode * pParent = node->m_pParent;
		_BinaryTreeNode * pCurrent = node;
		while (pParent != nullptr && pCurrent == pParent->m_pRight)//当直到当前节点是父节点的左子树的时候
		{
			pCurrent = pParent;
			pParent = pCurrent->m_pParent;
		}
		return pParent;
	}
}
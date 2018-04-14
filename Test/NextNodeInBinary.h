#pragma once
struct _BinaryTreeNode
{
	int m_nValue;
	_BinaryTreeNode * m_pLeft;
	_BinaryTreeNode * m_pRight;
	_BinaryTreeNode * m_pParent;
	_BinaryTreeNode(){}
	_BinaryTreeNode(int _m_nValue, _BinaryTreeNode * _m_pLeft = nullptr, _BinaryTreeNode * _m_pright = nullptr, _BinaryTreeNode *_m_pPrent = nullptr):m_nValue(_m_nValue),
		m_pLeft(_m_pLeft), m_pRight(_m_pright), m_pParent(_m_pPrent){}
};

//´´½¨¶þ²æÊ÷
_BinaryTreeNode * CreateBinaryTreeNode(int value);
void ConnectBinaryTreeNode(_BinaryTreeNode * pParent, _BinaryTreeNode * pLeft, _BinaryTreeNode * pRight);
void PrintTreeNode(const _BinaryTreeNode *pNode);
void PrintTree(const _BinaryTreeNode *pRoot);
_BinaryTreeNode * GetNext(_BinaryTreeNode *node);
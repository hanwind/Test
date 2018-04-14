#pragma once
#include <string>
#include <iostream>
using std::string;
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
	BinaryTreeNode(int _value):m_nValue(_value),m_pLeft(nullptr),m_pRight(nullptr){}
	BinaryTreeNode(){}
};
BinaryTreeNode * Construct(int *preorder, int * inorder, int length);
BinaryTreeNode * ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);
void PrintTree(const BinaryTreeNode *pRoot);
void PrintTreeNode(const BinaryTreeNode *pNode);
void DestroyTree(BinaryTreeNode * pRoot);

char* Serialize(BinaryTreeNode *root);
BinaryTreeNode* Deserialize(char *str);
void DeserializeCore(char *&str, BinaryTreeNode ** node);
string to_string(int value);
bool ReadStream(char *&str, int &number);
void SerializeCore(BinaryTreeNode * root, string & str);
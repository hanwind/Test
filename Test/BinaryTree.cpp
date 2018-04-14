#include "BinaryTree.h"
#include <exception>
#include <sstream>
BinaryTreeNode *Construct(int *preorder, int * inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length -1);
}

BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode * root = new BinaryTreeNode();
	int * rootInorder = startInorder;
	int length = 0;
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;
	//中序遍历中root节点的位置
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startInorder == *startPreorder)//只剩下最后一个节点了
			return root;
		else
			throw std::exception("Invalid Input1");
	}
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		rootInorder++;
	if(rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid Input2");
	length = rootInorder - startInorder;
	int * leftPreorderEnd = startPreorder +length;
	//构造左子树 ? 如果没有左子树
	if (length > 0)
		root->m_pLeft = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
	//构造右子树
	if ((endPreorder -leftPreorderEnd) > 0)
		root->m_pRight = ConstructCore(leftPreorderEnd+ 1,endPreorder, rootInorder+1, endInorder);
	return root;
}

void PrintTree(const BinaryTreeNode *pRoot)
{
	//打印一个节点
	PrintTreeNode(pRoot);
	if ( pRoot != nullptr)
	{
		if (pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);
		if (pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
}

void PrintTreeNode(const BinaryTreeNode *pNode)
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

void DestroyTree(BinaryTreeNode *pRoot)
{
	if (pRoot != NULL)
	{
		BinaryTreeNode * leftNode = pRoot->m_pLeft;
		BinaryTreeNode *rightNode = pRoot->m_pRight;
		delete pRoot;
		pRoot = nullptr;
		DestroyTree(leftNode);
		DestroyTree(rightNode);
	}
}
void SerializeCore(BinaryTreeNode * root, string & str)
{
	if(root == nullptr)
	{
		str.push_back('#');
		return;
	}
	string r = to_string(root->m_nValue);
	str += r;
	str += ',';
	SerializeCore(root->m_pLeft, str);
	SerializeCore(root->m_pRight, str);
}
char* Serialize(BinaryTreeNode *root) 
{    
	if(root == nullptr)
		return nullptr;
	string str;
	SerializeCore(root, str);
	char * result = new char[str.length()+1];
	int i;
	for(i = 0;i < str.length();++i)
		result[i] = str[i];
	result[i] = '\0';
	return result;
}

BinaryTreeNode* Deserialize(char *str) {
	if(str == nullptr)
		return nullptr;
	BinaryTreeNode * root = nullptr;
	DeserializeCore(str, &root);
	return root;
}
void DeserializeCore(char *&str, BinaryTreeNode ** node)//错误三改变为引用，因为每次回到上一层的时候需要这一层的指向的字符串是改变的，这种改变是要保留的
{
	int number = 0;//number没有初始化
	if(ReadStream(str,number))
	{
		*node = new BinaryTreeNode(number);
		(*node)->m_pLeft = nullptr;
		(*node)->m_pRight = nullptr;

		DeserializeCore(str, &((*node)->m_pLeft));
		DeserializeCore(str, &((*node)->m_pRight));
	}

}
bool ReadStream(char *&str, int &number)
{
	number = 0;
	if(*str == '#') 
	{
		++str;
		return false;
	}
	while(*str != '\0' && *str != ',')
	{
		number = number * 10 + ((*str) - '0');
		++str;
	}
	if(*str == ',')//当开始是','的时候程序怎么办
		++str;
	return true;

}
string to_string(int value)
{
	std::ostringstream stream;
	stream<<value;
	return stream.str();
}
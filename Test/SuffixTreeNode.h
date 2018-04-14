#pragma once
#include<map>
#include<vector>
using std::vector;
using std::map;
using std::string;
class SuffixTreeNode
{
	map<char, SuffixTreeNode *> children;
	char value;
	vector<int> indexes;//
public:
	SuffixTreeNode(){}
	void insertString(string s, int index)
	{
		indexes.push_back(index);
		if(s.length() > 0)
		{
			value = s[0];
			SuffixTreeNode * child = NULL;
			if(children.find(value) != children.end())//找到这个字符子节点
				child = children[value];
			else
			{
				child = new SuffixTreeNode();
				children[value] = child;
			}
			string remainder = s.substr(1);
			child->insertString(remainder, index);

		}
	}
	vector<int> getIndexes(string s)
	{
		if(s.length() == 0)
			return indexes;
		else
		{
			char first = s[0];
			if (children.find(first) != children.end())
			{
				string remainer = s.substr(1);
				return children[first]->getIndexes(remainer);
			}else
			{
				vector<int> empty;
				return empty;
			}
		}
	}
	~SuffixTreeNode()
	{
		map<char, SuffixTreeNode *>::iterator ite;
		for (ite = children.begin(); ite != children.end(); ++ite)
			delete (ite->second);

	}
};
class SuffixTree
{
	SuffixTreeNode *root;
public:
	SuffixTree(string s)
	{
		root = new SuffixTreeNode();
		for (int i = 0;i < s.size();++i)
		{
			string suffix = s.substr(i);
			root->insertString(suffix, i);
		}

	}
	vector<int> getIndexes(string s)
	{
		return root->getIndexes(s);
	}
	~SuffixTree()
	{
		if (root != NULL)
		{
			delete root;
			root = NULL;
		}
			
	}
};
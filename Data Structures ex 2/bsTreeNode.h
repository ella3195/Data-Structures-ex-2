#ifndef __BSTREENODE_H
#define __BSTREENODE_H

#include "person.h"

class BSTree;

class BSTreeNode
{

private:
	int key;
	const char *data;
	BSTreeNode* left, * right, * father;

public:
	BSTreeNode();
	BSTreeNode(int id, const char* name, BSTreeNode *left, BSTreeNode *right, BSTreeNode* father);
	~BSTreeNode();

	const char* getData();
	int getKey();

	void InOrder();
	void PreOrder();
	void PostOrder();

	friend class BSTree;
};


#endif // !__BSTREENODE_H


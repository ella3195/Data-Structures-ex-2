#ifndef __BSTREENODE_H
#define __BSTREENODE_H

#include "person.h"
#include "bsTree.h"

class BSTreeNode
{

private:
	int key;
	const char *data;
	BSTreeNode *left, *right;

public:
	BSTreeNode();
	BSTreeNode(int id, const char* name, BSTreeNode *left, BSTreeNode *right);
	~BSTreeNode();

	void InOrder();
	void PreOrder();
	void PostOrder();

	friend class BSTree;
};


#endif // !__BSTREENODE_H


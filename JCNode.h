#ifndef JCNODE_H
#define JCNODE_H
#include "../JCString/JCStringV2.h"


class JCNode
{
public:
	JCNode();
	JCNode(const JCString str);
	JCString data;
	JCNode* next;
	JCNode* prev;
};

#endif

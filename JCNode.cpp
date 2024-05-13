#include "JCNode.h"


JCNode::JCNode()
{
	this->next = nullptr;
	this->prev = nullptr;

}

JCNode::JCNode(const JCString str)
{
	this->data = str;
	this->next = nullptr;
	this->prev = nullptr;
}


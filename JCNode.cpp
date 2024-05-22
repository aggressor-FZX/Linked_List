////
// Name: Jeff Calderon
// Class Name: CS131
// Section:  33616
// Program 3 DoubleLinkedList
// Description: JCNode implementation 
// 
////
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


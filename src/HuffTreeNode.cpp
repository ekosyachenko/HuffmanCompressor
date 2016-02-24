#include "HuffTreeNode.h"
#include <iostream>
using namespace std;

HuffTreeNode::HuffTreeNode()
{

}

HuffTreeNode::HuffTreeNode(char symbol, int priority)
{
    this -> symbol = symbol;
    this -> priority = priority;
    this -> hasSymbolM = true;
}

HuffTreeNode::~HuffTreeNode()
{
    if (this -> left != nullptr)
    {
        delete this -> left;
    }
    if (this -> right != nullptr)
    {
        delete this -> right;
    } 
}


bool HuffTreeNode::operator ==(const HuffTreeNode &rhs)
{
    return (priority == rhs.priority);
}

bool HuffTreeNode::operator !=(const HuffTreeNode &rhs)
{
    return (priority != rhs.priority);
}

bool HuffTreeNode::operator >(const HuffTreeNode &rhs)
{
    return (priority > rhs.priority);
}

bool HuffTreeNode::operator >=(const HuffTreeNode &rhs)
{
    return (priority >= rhs.priority);
}

bool HuffTreeNode::operator <(const HuffTreeNode &rhs)
{
    return (priority < rhs.priority);
}

bool HuffTreeNode::operator <=(const HuffTreeNode &rhs)
{
    return (priority <= rhs.priority);
}


HuffTreeNode* HuffTreeNode::getLeft()
{
    return left;
}

HuffTreeNode* HuffTreeNode::getRight()
{
    return right;
}

int HuffTreeNode::getPriority()
{
    return priority;
}

unsigned char HuffTreeNode::getSymbol()
{
    return symbol;
}

bool HuffTreeNode::hasSymbol()
{
    return hasSymbolM;
}

HuffTreeNode* HuffTreeNode::operator+(HuffTreeNode & rhs)
{
    HuffTreeNode* newNode = new HuffTreeNode();
    newNode -> priority = priority + rhs.priority;
    newNode -> left = this;
    newNode -> right = &rhs;
    newNode -> hasSymbolM = false;

    return newNode;

}

string HuffTreeNode::treeToString()
{
    string result = "";
    nodeToString(this, result);
    return result;
}

void HuffTreeNode::nodeToString(HuffTreeNode* node, string & result)
{
    if (node == nullptr)
    {
        return;
    }
    result += "(";
    nodeToString(node -> left, result);

    if (node -> hasSymbol())
    {
        result += node -> symbol;
    }
    result += ", ";
    result += to_string(node -> priority);

    nodeToString(node -> right, result);
    result += ")";
}
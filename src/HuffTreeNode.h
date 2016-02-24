#ifndef HUFF_TREE_NODE
#define HUFF_TREE_NODE

#include <string>
using namespace std;

class HuffTreeNode
{
public:
    HuffTreeNode();
    HuffTreeNode(char symbol, int priority);
    ~HuffTreeNode();

    bool operator ==(const HuffTreeNode &rhs);
    bool operator !=(const HuffTreeNode &rhs);
    bool operator >(const HuffTreeNode &rhs);
    bool operator >=(const HuffTreeNode &rhs);
    bool operator <(const HuffTreeNode &rhs);
    bool operator <=(const HuffTreeNode &rhs);

    HuffTreeNode* getLeft();
    HuffTreeNode* getRight();

    int getPriority();
    unsigned char getSymbol();
    bool hasSymbol();

    HuffTreeNode* operator+(HuffTreeNode & rhs);

    string treeToString();
    void nodeToString(HuffTreeNode* node, string & result);

private:
    int priority;
    unsigned char symbol;
    bool hasSymbolM;

    HuffTreeNode * left = nullptr;
    HuffTreeNode * right = nullptr;

};

#endif

#include <iostream>

struct TreeNodeInParent{
    /*
     * 双亲结点表示的树  
    */
    int val;
    TreeNodeInParent* parent;
};

struct TreeNodeInChildAndBrother{
    /*
     * 孩子兄弟结点表示的树  
    */
    int val;
    TreeNodeInChild* firstChild;
    TreeNodeInChild* nextSibling;
};

struct TreeNodeInChild{
    /*
     * 孩子兄弟结点表示的树  
    */
    int val;
    TreeNodeInChild* firstChild;
};

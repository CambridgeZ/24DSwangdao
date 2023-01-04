//
// Created by Mac on 2023/1/4.
//

struct ArcNode{
    int ivex,jvex;//无向图连接的两个定点的编号
    ArcNode* ilink;//同样和i关联的下一个弧
    ArcNode* jlink;//同样和j关联的下一个弧
};
struct VNode{
    int data;
    ArcNode* firstEdge;//相关联的第一个弧节点
};

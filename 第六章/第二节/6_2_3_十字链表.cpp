//
// Created by Mac on 2023/1/4.
//

struct ArcNode{
    int tailvex,headvax;//弧尾节点和弧头节点的编号
    ArcNode *hlink;//有相同的头节点的下一个节点
    ArcNode *tlink;//有着相同尾节点的下一个节点
};

struct VNode{
    int data;//节点相关的信息
    ArcNode *firstin;//以这个节点作为弧尾的第一个节点
    ArcNode *firstout;//以这个作为弧头的第一个节点
};

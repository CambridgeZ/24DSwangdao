//
// Created by Mac on 2023/1/1.
//

#ifndef INC_24DSWANGDAO_LIST_2_3_7_20_H
#define INC_24DSWANGDAO_LIST_2_3_7_20_H

typedef struct Node{
    /*
     * 双向链表的节点
     */
    int data;
    int freq;//初始化为0
    struct Node *next;
    struct Node *pre;
}Node;

class List_2_3_7_20 {
private:
    Node * head;
public:
    List_2_3_7_20(){
        head = new Node;
    }
    void CreateList();
    int lengthOfLinklist();
    void PrintList();
    void Locate(int x);
};


#endif //INC_24DSWANGDAO_LIST_2_3_7_20_H

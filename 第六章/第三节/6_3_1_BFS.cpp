//
// Created by Mac on 2023/1/9.
//

#include <iostream>
#include <queue>

#define MAXN 10
using namespace std;
struct Graph{
    int vexNumber;
    int arc[MAXN+1][MAXN+1];
    int vex[MAXN];
};

void CreateGraph(Graph& G){
    /*
     * 创建的是无向图
     */

    /*
     * 测试数据
     * test 1
     * 5
     * 8
     * 1 2   1 3     1 4     1 5     2 4     3 4     3 5     4 5
     * test 2
     * 5
     * 7
     * 1 2   1 4     1 5     2 4     3 4     3 5     4 5
     */
    ::memset(G.arc,0,sizeof(G.arc));
    int n;
    cin>>n;//顶点个数
    G.vexNumber=n;
    for(int i=1;i<=n;i++){
        G.vex[i]=i;
    }
    cin>>n;//输入边的个数
    while(n--){
        int i,j;
        cin>>i>>j;

        G.arc[i][j]=1;
        G.arc[j][i]=1;

    }
};
bool visited[MAXN+1];
queue<int> Q;

void BFS(Graph G,int i){
    cout<<G.vex[i]<<" ";//访问当前的节点
    visited[i]= true;
    Q.push(i);//进入队列
    while(!Q.empty()){
        int j=Q.front();//类似于层序遍历
        Q.pop();
        for(int k=1;k<=G.vexNumber;k++){
            if(G.arc[k][j]==1&&visited[k]== false){//如果两个节点之间存在边并且这个节点没有访问过就访问这个节点
                //访问和当前节点相邻的节点，并且将这些节点入队列
                cout<<G.vex[k]<<" ";
                visited[k]= true;
                Q.push(k);
            }
        }
    }

}

void BFSTraverse(Graph G){
    ::memset(visited,false, sizeof(visited));
    for(int i=1;i<=G.vexNumber;i++){//对于其中没有被访问过的节点就从这个节点开始进行访问
        if(!visited[i])
            BFS(G,i);
    }
}

int main(){
    Graph G;
    CreateGraph(G);
    BFSTraverse(G);
    return 0;
}

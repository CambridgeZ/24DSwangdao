//
// Created by Mac on 2023/1/9.
//
/*
 * 判断一个无向图是不是树
 * 先数边的个数是不是定点个数-1，在判断这个图是不是连通图
 */

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

bool isArcLess1ThanVex(Graph const & G){
    //判断边的个数是不是恰好比顶点的个数少1
    int count=0;
    for(int i=1;i<=G.vexNumber;i++){
        for(int j=i+1;j<=G.vexNumber;j++){
            if(G.arc[i][j]==1)
                count++;
        }
    }
    if(count==G.vexNumber-1)
        return true;
    else
        return false;
}

void DFS(Graph G,int i){
    //深度优先遍历
    visited[i]= true;

    for(int j=1;j<=G.vexNumber;j++){
        if(G.arc[i][j]==1&&visited[j]==false){
            DFS(G,j);
        }
    }
}

bool isConnect(Graph G){
    ::memset(visited, false,sizeof (visited));
    DFS(G,1);
    for(int i=1;i<=G.vexNumber;i++){
        //一次DFS之后如果还有点没有被访问说明不是连通的
        if(visited[i]== false)
            return false;
    }
    return true;
}

bool isTree(Graph G){
    if(isArcLess1ThanVex(G)&& isConnect(G))
        return true;
    else
        return false;
}

int main(){
    Graph G;
    CreateGraph(G);
    cout<<isTree(G)<<endl;
    return 0;
}
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

void DFS(Graph G,int i){
    cout<<G.vex[i]<<" ";
    visited[i]=true;
    for(int k=1;k<=G.vexNumber;k++){
        if(G.arc[k][i]==1&&visited[k]==false){
            DFS(G,k);
        }
    }
}
void DFSTravers(Graph G){
    ::memset(visited,false,sizeof (visited));
    for(int i=1;i<=G.vexNumber;i++){
        if(visited[i]== false){
            DFS(G,i);
        }
    }
}

int main(){
    Graph G;
    CreateGraph(G);
    DFSTravers(G);
    return 0;
}
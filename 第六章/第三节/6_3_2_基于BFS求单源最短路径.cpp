//
// Created by Mac on 2023/1/9.
//

#include <iostream>
#include <queue>

#define MAXN 10
#define INF 0x3fffffff
using namespace std;
struct Graph{
    int vexNumber;
    int arc[MAXN+1][MAXN+1];
    int vex[MAXN];
};

void CreateGraphWithWeight(Graph& G){
    /*
     * 创建的是带权无向图
     */

    /*
     * 测试数据
     * test 1
     * 5
     * 8
     * 1 2 9   1 3 11     1 4 1     1 5 2    2 4 3     3 4 12     3 5 5     4 5 7
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
        int i,j,weight;
        cin>>i>>j>>weight;

        G.arc[i][j]=weight;
        G.arc[j][i]=weight;
    }
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

int dis[MAXN+1];
bool visited[MAXN+1];

void BFSMinDistance(Graph G,int u){
    queue<int> Q;
    ::memset(dis,INF,sizeof dis);
    ::memset(visited,0,sizeof (visited));
    visited[u]= true,dis[u]=0;
    Q.push(u);
    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        for(int i=1;i<=G.vexNumber;i++){
            if(G.arc[u][i]==1&&!visited[i]){
                dis[i]=dis[u]+1;
                visited[u]= true;
            }
        }

    }
}

int main(){
    Graph G;
    CreateGraph(G);
    BFSMinDistance(G,1);
    for(int i=1;i<=G.vexNumber;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}



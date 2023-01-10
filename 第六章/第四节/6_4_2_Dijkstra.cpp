//
// Created by Mac on 2023/1/10.
//


#include <iostream>

#define MAXN 10
#define INF 100000
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
     * 1 2 3   1 4 9    1 5 4    2 4 1    3 4 2    3 5 5    4 56
     */
    int n;
    cin>>n;//顶点个数
    G.vexNumber=n;
    for(int i=1;i<=n;i++){
        G.vex[i]=i;
    }
    for(int i=0;i<=G.vexNumber;i++){
        for(int j=0;j<=G.vexNumber;j++){
            G.arc[i][j]=INF;
        }
    }
    cin>>n;//输入边的个数
    while(n--){
        int i,j,weight;
        cin>>i>>j>>weight;

        G.arc[i][j]=weight;
        G.arc[j][i]=weight;
    }
    for(int i=1;i<=G.vexNumber;i++)
        G.arc[i][i]=0;
}

int dist[MAXN+1];//当前从源点到其他的点的最短路径
int path[MAXN+1];//从源点到顶点之间到最短路径到的前驱节点
bool visited[MAXN+1];//用来区分已经是确定最小值的集合和还没有确定最小值的集合

void shortestPathDijkstra(Graph G,int source){
    ::memset(visited,false,sizeof (visited));
    dist[source]=0;
    path[source]=source;
    visited[source]=true;
    for(int i=1;i<=G.vexNumber;i++)
        dist[i]=G.arc[source][i];//将dist中的值全部设置为arc中的值

    int pre=source;//当前最短路径的前驱节点
    for(int k=1;k<G.vexNumber;k++){//重复这个过程n-1次
        int min=INF,minIndex=0;
        for(int i=1;i<=G.vexNumber;i++){
            //找到当前的情况下已经达成的路径当中最小的,并且不在已经确定最小的集合当中
            if(dist[i]<min&&!visited[i]){
                min=dist[i];
                minIndex=i;
            }
        }

        visited[minIndex]=true;
        path[minIndex]=pre;
        pre=minIndex;

        for(int i=1;i<=G.vexNumber;i++){
            if(!visited[i]&&G.arc[pre][i]+dist[pre]<dist[i]) {
                //如果当前的节点和pre节点之间的路径长度加上当前pre节点到当前节点的路径得到的少于当前所谓的最短路径就修改
                dist[i] = G.arc[pre][i] + dist[pre];
                path[i]=pre;
            }
        }
    }
}

int main(){
    Graph G = {};
    CreateGraphWithWeight(G);
    shortestPathDijkstra(G,1);
    for(int i=1;i<=G.vexNumber;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
    for(int i=1;i<=G.vexNumber;i++)
        cout<<path[i]<<" ";
    cout<<endl;
    return 0;
}



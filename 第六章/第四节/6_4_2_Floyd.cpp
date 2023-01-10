//
// Created by Mac on 2023/1/11.
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

int dist[MAXN+1][MAXN+1];

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

void shortestFloyd(Graph G){
    for(int i=1;i<=G.vexNumber;i++){
        for(int j=1;j<=G.vexNumber;j++)
            dist[i][j]=G.arc[i][j];
    }

    for(int k=1;k<=G.vexNumber;k++){
        //这个必须要保证k放在最外层
        for(int i=1;i<=G.vexNumber;i++){
            for(int j=1;j<=G.vexNumber;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

int main(){
    Graph G;
    CreateGraphWithWeight(G);
    shortestFloyd(G);
    for(int i=1;i<=G.vexNumber;i++){
        for(int j=1;j<=G.vexNumber;j++){
            cout<<G.arc[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//
// Created by Mac on 2023/1/16.
//

#include <iostream>
#include <stack>

#define MAXN 10
#define INF 100000
using namespace std;
struct Graph{
    int vexNumber;
    int arc[MAXN+1][MAXN+1];
    int vex[MAXN];
};

int dist[MAXN+1][MAXN+1];

void CreateGraphWithDirection(Graph& G){
    /*
     * 创建的是带权有向图
     */

    /*
     * 测试数据
     * test 1
     * 5
     * 8
     * 1 2    1 3      1 4      1 5    2 4      3 4      3 5      4 5
     * test 2
     * 5
     * 7
     * 1 2    1 4     1 5     2 4     3 4     3 5     4 5
     */

    /*
     * 有向图横坐标表示的是开始的位置
     */
    int n;
    cin>>n;//顶点个数
    G.vexNumber=n;
    for(int i=1;i<=n;i++){
        G.vex[i]=i;
    }
    for(int i=0;i<=G.vexNumber;i++){
        for(int j=0;j<=G.vexNumber;j++){
            G.arc[i][j]=0;
        }
    }
    cin>>n;//输入边的个数
    while(n--){
        int i,j;
        cin>>i>>j;

        G.arc[i][j]=1;

    }
    for(int i=1;i<=G.vexNumber;i++)
        G.arc[i][i]=0;
}

bool TopologicalSort(Graph G){
    stack<int> S;//栈，用于存储入度为0的节点
    int indegree[G.vexNumber+1];
    ::memset(indegree,0,sizeof (indegree));
    for(int i=1;i<=G.vexNumber;i++){
        //入度为0意味着这个点的纵坐标上都是0；
        indegree[i]=0;
        for(int j=1;j<=G.vexNumber;j++){
            indegree[i]+=G.arc[j][i];
        }
        if(indegree[i]==0){
            S.push(i);
        }
    }

//    for(int i=1;i<G.vexNumber;i++){
//        cout<<indegree[i]<<" ";
//    }
//    cout<<endl;

    int count=0;
    while(!S.empty()){
        cout<<S.top()<<" ";
        int i=S.top();
        S.pop();
        count++;
        for(int j=1;j<=G.vexNumber;j++){
            if(G.arc[i][j]==1){
                indegree[j]--;
                if(indegree[j]==0){
                    S.push(j);
                }
            }
        }
    }
    if(count==G.vexNumber)
        return true;
    else
        return false;
}

int main(){
    Graph G;
    CreateGraphWithDirection(G);
    TopologicalSort(G);
    return 0;
}


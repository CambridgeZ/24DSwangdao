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
     * 1 2 9   1 3 11     1 4 1     1 5 2    2 4 3     3 4 12     3 5 5     4 5 7
     * test 2
     * 5
     * 7
     * 1 2 3   1 4 9    1 5 4    2 4 1    3 4 2    3 5 5    4 56
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
        int i,j,weight;
        cin>>i>>j>>weight;

        G.arc[i][j]=weight;

    }
    for(int i=1;i<=G.vexNumber;i++)
        G.arc[i][i]=0;
}
void test(int a[],int n);
int ve[MAXN+1];//每个节点的最早发生时间
int vl[MAXN+1];//每个节点的最迟发生时间

bool GetTheEarlistTime(Graph G){
    ::memset(ve,0,sizeof ve);
    stack<int> S;//栈，用于存储入度为0的节点
    int count=0;
    int indegree[G.vexNumber+1];
    ::memset(indegree,0,sizeof (indegree));
    for(int i=1;i<=G.vexNumber;i++){
        //入度为0意味着这个点的纵坐标上都是0；
        indegree[i]=0;
        for(int j=1;j<=G.vexNumber;j++){
            if(G.arc[j][i]!=0)
                indegree[i]++;
        }
        if(indegree[i]==0){
            S.push(i);
        }
    }

//    test(indegree,G.vexNumber);


    while(!S.empty()){
//        cout<<S.top()<<" ";
        int i=S.top();
        S.pop();
        count++;
        for(int j=1;j<=G.vexNumber;j++){
            if(G.arc[i][j]!=0){
                indegree[j]--;
                if(indegree[j]==0){
                    S.push(j);
                }
                if(ve[j]<ve[i]+G.arc[i][j]){
                    ve[j]= ve[i]+G.arc[i][j];
                }
            }
        }
    }
    if(count==G.vexNumber)
        return true;
    else
        return false;
}

bool GetTheLatestTime(Graph G,int longestway){
    //求出最后发生时间
//    ::memset(vl,longestway,sizeof(ve));
    stack<int> S;//栈，用于存储入度为0的节点
    int count=0;
    int outdegree[G.vexNumber+1];
    ::memset(outdegree,0,sizeof (outdegree));
    for(int i=1;i<=G.vexNumber;i++){
        //入度为0意味着这个点的纵坐标上都是0；
        outdegree[i]=0;
        for(int j=1;j<=G.vexNumber;j++){
            if(G.arc[i][j]!=0)
                outdegree[i]++;
        }
        if(outdegree[i]==0){
            S.push(i);
        }
    }

//    test(outdegree,G.vexNumber);


    while(!S.empty()){
//        cout<<S.top()<<" ";
        int i=S.top();
        S.pop();
        count++;
        for(int j=1;j<=G.vexNumber;j++){
            if(G.arc[j][i]!=0){
                outdegree[j]--;
                if(outdegree[j]==0){
                    S.push(j);
                }
                if(vl[j]>vl[i]-G.arc[j][i]){
                    vl[j]= vl[i]-G.arc[j][i];
                }
            }
        }
    }
    if(count==G.vexNumber)
        return true;
    else
        return false;
}

void test(int a[],int n){
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void findTheKeyWay(Graph G){
    GetTheEarlistTime(G);
//    test(ve,G.vexNumber);
    int longestWayLength=0;
    for(int i=1;i<=G.vexNumber;i++)
        if(ve[i]>longestWayLength) {
            longestWayLength = ve[i];
        }
    for(int i=0;i<MAXN+1;i++)
        vl[i]=v[e];

    GetTheLatestTime(G,longestWayLength);
//    test(vl,G.vexNumber);
    for(int i=1;i<=G.vexNumber;i++){
        if(ve[i]==vl[i])
            cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    Graph G;
    CreateGraphWithDirection(G);
    findTheKeyWay(G);
    return 0;
}
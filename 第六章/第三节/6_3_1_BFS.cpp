//
// Created by Mac on 2023/1/9.
//

#include <iostream>
#define MAXN 10
using namespace std;
struct Graph{
    int arc[MAXN+1][MAXN+1];
    int vex[MAXN];
};

void CreateGraph(Graph& G){
    /*
     * 创建的是无向图
     */
    ::memset(G.arc,0,sizeof(G.arc));
    int n;
    cin>>n;//顶点个数
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

int main(){

}

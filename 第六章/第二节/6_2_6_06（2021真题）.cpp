//
// Created by Mac on 2023/4/19.
//
# include <iostream>
# include <algorithm>

using namespace std;
typedef struct {//Graph
    int numVertices;
    int numEdges;
    char vexs[100];
    int edges[100][100];
} MGraph;

void createMGraph(MGraph &G) {
    cin >> G.numVertices >> G.numEdges;
    for (int i = 0; i < G.numVertices; i++) {
        cin >> G.vexs[i];
    }
    for (int i = 0; i < G.numVertices; i++) {
        for (int j = 0; j < G.numVertices; j++) {
            G.edges[i][j] = 0;
        }
    }
    for (int i = 0; i < G.numEdges; i++) {
        char a, b;
        cin >> a >> b;
        int x, y;
        for (int j = 0; j < G.numVertices; j++) {
            if (G.vexs[j] == a) {
                x = j;
            }
            if (G.vexs[j] == b) {
                y = j;
            }
        }
        G.edges[x][y] = 1;
        G.edges[y][x] = 1;
    }
}

/*
 * 本来以为这道题超纲了用到了离散数学当中的知识，在仔细读题之后可以发现题目中已经给出来了如何判断欧拉图的方法，我还以为是条件，所以一定要好好读题
 *
 * 题目思路：
 * 对于图统计其中每个节点的度，如果这个图中节点为奇数的个数为0或者2，那么就说明这个是半欧拉图，否则就不是欧拉图
 */

int isExistEL(MGraph G){
    int degree[G.numVertices];
    int odd_nums=0;
    ::memset(degree,0,sizeof (degree));
    for(int i=0;i<G.numVertices;i++){
        for(int j=0;j<G.numVertices;j++){
            if(G.edges[i][j]!=0)
                degree[i]++;
        }
        if(degree[i]%2)
            odd_nums++;
    }
    if(odd_nums==0||odd_nums==2)
        return 1;
    else
        return 0;
}

//test
/*
  input 1
    6 7
    A B C D E F
    1 2
    1 3
    1 4
    2 3
    2 5
    3 4
    4 5
 */
int main() {
    MGraph G;
    createMGraph(G);
    if(isExistEL(G))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
/*
 * 时间复杂度为O(n^2)
 * 空间复杂度为O(n)
 */



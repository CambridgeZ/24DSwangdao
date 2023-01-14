//
// Created by Mac on 2023/1/15.
//
/*
 * 根据某个树的层序遍历结果和每个节点的度编写
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void CreateTreeByLayerOrderAndDegree(string s1,string s2){
    vector<string> layers;
    string layer="";
    layer=+s1[0];
    layers.push_back(layer);
    int nextLayerlength=s2[0]-'0';
    int i=1;
    while(i<s1.length()) {
        for (int j = 0; j < nextLayerlength; i++, j++) {

        }
    }
}


int main(){

}
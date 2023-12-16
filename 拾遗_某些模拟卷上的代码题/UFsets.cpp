#include <iostream>
#include <cstring>

using namespace std;

class UFSets{
private :
	int* UFSets_data;
public :
	UFSets(int n){
		UFSets_data = new int[n];
		memset(UFSets_data,-1,sizeof(UFSets_data));
	}
    ~UFSets(){
        delete [] UFSets_data;
    }
    int Find(int x){
        while(UFSets_data[x] >= 0){
            x = UFSets_data[x];
        }
        return x;
    }

    void Union(int Root1,int Root2){
        if(Find(Root1) == Find(Root2)){
            return;
        }
        else {
            UFSets[Root1] += UFSets[Root2];
            UFSets_data[Root2]=Root1;
        }
    }
};

void test(){
    //test UFSets
    UFSets u(10);
    u.Union(1,2);
    u.Union(3,4);
    u.Union(5,6);
    u.Union(7,8);
}

// int main(int argc, char *argv[]) {
// 	test();
//     return 0;
// }
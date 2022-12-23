#include <iostream>
#include <queue>

using namespace std;
queue<int> car;//客车队列
queue<int> lorry;//货车队列
queue<int> vehicle;//车辆队列

void manager(){
    while(vehicle.size()<=10){
        if(lorry.size()==0){
            while(vehicle.size()<=10){
                vehicle.push(car.front());
                car.pop();
            }
        }
        else {
            for(int i=0;i<4;i++){
                if(car.size()>0){
                    vehicle.push(car.front());
                    car.pop();
                }
                else if(lorry.size()> 0){
                    vehicle.push(lorry.front());
                    lorry.pop();
                }
                else continue;
            }
            if(lorry.size()> 0){
                    vehicle.push(lorry.front());
                    lorry.pop();
                }
        }
    }
}

int main(){

}
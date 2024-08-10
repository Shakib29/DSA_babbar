#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
struct petrolpump {
    int petrol;  // petrol available at the petrol pump
    int distance; // distance to the next petrol pump
};
int tour(petrolpump p[],int n){
    int deficit=0;
        int balance=0;
            int start=0;

      for(int i=0;i<n;i++){
        balance+=p[i].petrol-p[i].distance;
        if(balance<0){
            deficit+=balance;
            start=i+1;
            balance=0;
        }
      }      
      if(deficit+balance>=0){
        return start;
      }else{
        return -1;
      }
}

int main() {
    petrolpump p[] = {{6, 4}, {3, 6}, {7, 3}};
    int n = sizeof(p) / sizeof(p[0]);
    int start = tour(p, n);

    if (start != -1) {
        cout << "Start at petrol pump index: " << start << endl;
    } else {
        cout << "No solution possible" << endl;
    }

    return 0;
}
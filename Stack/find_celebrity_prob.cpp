#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(vector< vector<int>> &M,int a,int b,int n){
    if(M[a][b]==1){
        return true;
    }else{
        return false;
    }
}

int celebrity(vector< vector<int>> &M,int n){
stack<int> s;
//1 push all elements into the stack
for(int i=0;i<n;i++){
s.push(i);
}

//2 get elements and compare them
while(s.size()>1){
    int a=s.top();
    s.pop();
    int b=s.top();
    s.pop();

    if(knows(M,a,b,n)){
        s.push(b);

    }else{
        s.push(a);
    }

}
int ans=s.top();
int candidate=s.top();
//3 last element jo baccha hai potentially hosakta hai celebrity,,so lets check
bool rowcheck=false;
int zerocount=0;
for(int i=0;i<n;i++){
    if(M[ans][i]==0){
        zerocount++;
    }
}
if(zerocount==n){
    rowcheck=true;
}

bool colcheck=false;
int onecount=0;
for(int i=0;i<n;i++){
    if(M[i][ans]==0){
        onecount++;
    }
}
if(onecount==n-1){
    colcheck=true;
}


if(rowcheck==true&&colcheck==true){
    return ans;
}else{
    return -1;
}
}

int main(){
int n = 4;
    vector<vector<int>> M = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };

    int celeb = celebrity(M, n);

    if (celeb == -1) {
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity found at index: " << celeb << endl;
    }

    return 0;
}
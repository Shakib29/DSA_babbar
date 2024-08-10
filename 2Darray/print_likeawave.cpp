#include<iostream>
#include<vector>
using namespace std;

vector<int> printwave(int arr[][3],int r,int c){
    vector<int> ans;

for(int j=0;j<c;j++){
  if(j&1){
   for(int i=r-1;i>=0;i--){
    // cout<<arr[i][j]<<" ";
    ans.push_back(arr[i][j]);
   }
   }
  else{
    for(int i=0;i<r;i++){
    // cout<<arr[i][j]<<" ";
     ans.push_back(arr[i][j]);
   }
  }
  

}
 return ans;
}


int main(){
 int arr[3][3];
 cout<<"enter elements:";
 
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cin>>arr[i][j];
    }
}
   vector<int> result = printwave(arr, 3, 3);

    cout << "Wave print of the matrix: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

vector<int> printspiral(int arr[][3],int row,int col){
   int startingrow=0;
   int startingcol=0;
   int endingrow=row-1;
   int endingcol=col-1;
   int count=0;
   vector<int> ans;
   int total=row*col;
   while(count<total){
   for(int i=startingcol;count<total&&i<=endingcol;i++){
    ans.push_back(arr[startingrow][i]);
    count++;
   }
   startingrow++;
    for(int i=startingrow;count<total&&i<=endingrow;i++){
       ans.push_back(arr[i][endingcol]); 
        count++;
    }
    endingcol--;
    for(int i=endingcol;count<total&&i>=startingcol;i--){
        ans.push_back(arr[endingrow][i]);
        count++;
    }
    endingrow--;
    for(int i=endingrow;count<total&&i>=startingrow;i--){
        ans.push_back(arr[i][startingcol]);
        count++;
    }
    startingcol++;


   }
  return ans;
}




int main(){
int arr[3][3];
cout<<"Enter elements"<<endl;
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>arr[i][j];

    }
}
  vector<int> result = printspiral(arr, 3, 3);

    cout << "Spiral print of the matrix: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

}
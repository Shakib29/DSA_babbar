#include<iostream>
using namespace std;

bool findelement(int arr[][4],int target,int rows,int col){

for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
          if(arr[i][j]==target){
            return 1;
          }
        }
    }
    return 0;
}
//  row wise sum print
void prinsum(int arr[][4],int rows,int col){
cout<<"printing sum  ";
for(int i=0;i<3;i++){
    int sum=0;
        for(int j=0;j<4;j++){
            sum+=arr[i][j];
        }
        cout<<"sum => "<<sum;
    }

}
//  column wise sum print
void printcolsum(int arr[][4],int rows,int col){
cout<<"printing sum  ";
for(int j=0;j<4;j++){
    int sum=0;
        for(int i=0;i<3;i++){
            sum+=arr[i][j];
        }
        cout<<"sum => "<<sum;
    }

}

int printmaxrow(int arr[][4],int rows,int col){
int maxi=INT32_MIN;
int rowindex=-1;
for(int i=0;i<3;i++){
    int sum=0;
        for(int j=0;j<4;j++){
            sum+=arr[i][j];
        }
        if(sum>maxi){
            maxi=sum;
            rowindex=rows;
        }
       
    }

cout<<"maximum sum is => "<<maxi;
    return rowindex;
}


int main(){
    int arr[3][4];
    int rows=3;
    int col=4;
    cout<<"enter elements :"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"enter target element:"<<endl;
    int target;
    cin>>target;
    // findelement(arr,target,rows,col);
    // if(findelement(arr,target,rows,col)){
    //     cout<<endl<<"element is present : "<<endl;
    // }else{
    //        cout<<endl<<"element is not present : "<<endl;
        
    // }
    // prinsum(arr,rows,col);
    // printcolsum(arr,rows,col);
   

cout<<"maximum sum is at index "<< printmaxrow(arr,rows,col)<<endl;
}
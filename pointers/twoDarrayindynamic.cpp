#include<iostream>
using namespace std;
int main(){
    int row,col;
    cout<<"Enter row and col"<<endl;
    cin>>row>>col;
    int **arr=new int*[row];
   
    for(int i=0;i<row;i++){
        arr[i]=new int;

    }
    cout<<"enter elments"<<endl;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
   cout<<"printing elements"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }



    // releasing memory first of all arrays
    
    for(int i=0;i<row;i++){
        delete []arr[i];
    }

    //  releasing memory of all pointers
    delete []arr;
}
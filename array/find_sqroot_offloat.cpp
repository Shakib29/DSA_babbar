#include<iostream>
using namespace std;
long long int  binarysearch(int n){
 int s=0;
 int e=n;
 long long int mid=s+(e-s)/2;
long long int ans=-1;
while(s<=e){
    long long int square=mid*mid;
    if(square==n){
        return mid;

    }
    else if(square<n){
    ans=mid;
    s=mid+1;
    }
    else{
        e=mid-1;
    }
    mid=s+(e-s)/2;
}
  return ans;
}
int sqr(int x){
    return binarysearch(x);
}
double precise(int n,int precision,int tempsoln){
    double factor=1;
    double ans=tempsoln;
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for(double j=ans;j*j<=n;j+=factor){
         ans=j;
        }
    }
    return ans;
}
int main(){
   int n;
   cin>>n;
   int firstpart=sqr(n);
   double final=precise(n,3,firstpart);
   cout<<final;
}
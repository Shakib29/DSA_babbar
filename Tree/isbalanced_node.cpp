#include<iostream>
using namespace std;
class node
{
public:
  int data;
  node *left;
  node *right;

  node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};
 //aproach 1
// int height(node *root){
//   //base case
//   if(root==NULL){
//     return 0;
//   }
//   int  h1= height(root->left);
// int h2= height(root->right);
//   int ans=max(h1,h2)+1;
//   return ans;
// }

// bool isbalanced(node* root){
// //base case
// if(root==NULL){
//   return true;

// }
// int left=isbalanced(root->left);
// int right=isbalanced(root->right);
// int diff=abs(height(root->left)-height(root->right))<=1;

// if(left&&right&&diff){
//   return 1;
// }else{
//   return false;
// }


//}
pair<bool,int> isbalancedfast(node *root){
  if(root==NULL){
    pair<bool,int> p;
    pair<bool,int> p=make_pair(true,0);
  }
  pair<int,int> left=isbalancedfast(root->left);
pair<int,int> right=isbalancedfast(root->right);

bool leftans=left.first;
bool rightans=right.first;

 bool diff=abs(left.second-right.second)<=1;

 pair<bool,int> ans;
 ans.second=max(left.second,right.second)+1;


if( leftans && rightans && diff){
  ans.first=true;
}else{
  ans.first=false;
  
}
return ans;
}
int main(){

}
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

class info{
  public:
  int mini;
  int maxi;
  bool isbst;
  int size;

};

info solve(node *root,int &ans){
 if (root == NULL) {
        return {INT16_MAX, INT16_MIN, true, 0};  // Correct initialization for NULL nodes
    }
info left=solve(root->left,ans);
info right=solve(root->right,ans);
info currnode;
currnode.size=left.size+right.size+1;
currnode.maxi=max(root->data,right.maxi);
currnode.mini=min(root->data,left.mini);

if(left.isbst&&right.isbst&&(root->data>left.maxi&&root->data<right.mini)){
  currnode.isbst=true;
}else{
  currnode.isbst=false;
}

//answer update
if(currnode.isbst){
  ans=max(ans,currnode.size);
}
return currnode;
}

int largetsbst(node *root){
int maxsize=0;
info temp=solve(root,maxsize);
return maxsize;
}
int main()
{
  node* root = new node(10);
    root->left = new node(5);
    root->right = new node(20);
    root->left->left = new node(2);
    root->left->right = new node(8);
    root->right->left = new node(15);
    root->right->right = new node(30);
    cout<< largetsbst(root);
      
   
    
 
} 
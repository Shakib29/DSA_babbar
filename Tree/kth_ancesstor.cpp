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

node * solve(node* root,int &k,int Node){
  if(root==NULL){
    return NULL;
  }
  if(root->data==Node){
    return root;
  }
  node *leftans=solve(root->left,k,Node);
    node *rightans=solve(root->right,k,Node);
 
 if(leftans!=NULL&&rightans==NULL){
  k--;
  if(k<=0){
    k=INT32_MAX;
    return root;
  }
  return leftans;
 }

 if(leftans==NULL&&rightans!=NULL){
  k--;
  if(k<=0){
    k=INT32_MAX;
    return root;
  }
  return rightans;
 }
  return NULL;
}
int find_Kth_ancestor(node *root,int k,int Node){
  node* ans=solve(root,k,Node);
  if(ans==NULL||ans->data==Node){
    return -1;
  }
  else{
    return ans->data;
  }
}

int main()
{
  // Create a sample binary tree
  node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
cout<<find_Kth_ancestor(root,2,4);

   

 
}
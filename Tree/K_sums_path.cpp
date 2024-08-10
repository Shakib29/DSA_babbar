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

void solve(node *root,int k,int  &count,vector<int> path){
  if(root==NULL){
    return;
  }
  path.push_back(root->data);

  solve(root->left,k,count,path);
  solve(root->right,k,count,path);
  //check for k sum

  int size=path.size();
  int sum=0;
  for(int i=size-1;i>=0;i--){
    sum+=path[i];
    if(sum==k){
      count++;
    }
  }
  path.pop_back();
}

int sumk(node *root,int k){
  vector<int>path;
  int count=0;
  solve(root,k,count,path);
  return count;
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
cout<<sumk(root,3);

   

 
}
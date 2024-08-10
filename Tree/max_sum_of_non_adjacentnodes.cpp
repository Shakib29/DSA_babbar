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

pair<int,int> solve(node *root){
  if(root==NULL){
    pair<int,int> p=make_pair(0,0);
    return p;
  }
  pair<int,int> leftans=solve(root->left);
    pair<int,int> rightans=solve(root->right);

    pair<int,int> ans;

    ans.first=root->data+leftans.second+rightans.second;

    ans.second=max(leftans.first,leftans.second)+max(rightans.first,rightans.second);
    return ans;


}

int getmaxsum(node *root){
  pair<int,int> ans=solve(root);
 return max(ans.first,ans.second);
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
cout<<getmaxsum(root);

   

 
}
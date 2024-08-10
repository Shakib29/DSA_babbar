#include <iostream>
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
pair<bool,int> issumfast(node * root){
  if(root==NULL){
      pair<bool,int> p= make_pair(true,0);
      return p;
  }
  if(root->left==NULL&&root->right==NULL){
    pair<bool,int> p=make_pair(false,root->data);
    return p;
  }
  pair<bool,int> leftans=issumfast(root->left);
   pair<bool,int> rightans=issumfast(root->right);

     bool left=leftans.first;
     bool right=rightans.first;
     bool cond= root->data==leftans.second+rightans.second;
     pair<bool,int> ans;

     if(left&&right&&cond){
      ans.first=true;
      ans.second=2*root->data;
     }
     else{
      ans.first=false;
     }

     return ans;
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
  return 0;
}
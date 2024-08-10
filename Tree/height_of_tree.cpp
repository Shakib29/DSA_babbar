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
int len_0f_tree(node * root){
  //base case
  if(root==NULL){
    return 0;
  }
int  h1= len_0f_tree(root->left);
int h2= len_0f_tree(root->right);
  int ans=max(h1,h2)+1;
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
   cout<<len_0f_tree(root);
  return 0;
}
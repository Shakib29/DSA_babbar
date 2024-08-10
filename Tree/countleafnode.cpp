#include<iostream>
using namespace std;
class node{
  public:
  int data;
  node* left;
  node* right;

  node(int d){
    this->data=d;
    this->left=NULL;
    this->right=NULL;
  }
};


void inorder(node *root,int &count){
  //base case
  if(root==NULL){
    return;
  }
  inorder(root->left,count);
    if(root->left==NULL&&root->right==NULL){
     count++;
    }
  inorder(root->right,count);
}

int countleaf(node *root){
  int count;
  inorder(root,count);
  return count;
}

int main(){
   // Create a sample binary tree
  node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);

  int leafCount = countleaf(root);
  cout << "Number of leaf nodes: " << leafCount << endl;

  return 0;
}
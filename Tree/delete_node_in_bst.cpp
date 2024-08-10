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







node* minval(node*root){
  node *temp=root;
  while (temp->left!=NULL)
  {
    temp=temp->left;
  }
  return temp;
}



node* deletenode(node*root,int element){
  if(root==NULL){
    return root;
  }
  if(root->data==element){
  //leaf node
  if(root->left==NULL&&root->right==NULL){
    delete root;
    return NULL;
  }
  //1 child

  //left child
  if(root->left!=NULL&&root->right==NULL){
    node* temp=root->left;
    delete root;
    return temp;
  }
  //right child
  if(root->left==NULL&&root->right!=NULL){
    node* temp=root->right;
    delete root;
    return temp;
  }

  //2 child 
  if(root->left!=NULL&&root->right!=NULL){
    int min=minval(root->right)->data;
    root->data=min;
    root->right=deletenode(root->right,min);
    return root;
  }
  }
}

int main()
{
  node *root = NULL;
   

    
   
 
 
 
} 
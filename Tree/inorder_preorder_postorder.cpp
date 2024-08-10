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

node* buildtree(node * root){
  cout<<"  enter data :";
  int data;
  cin>>data;
  root=new node(data);

  if(data==-1){
    return NULL;
  }

  cout<<"enter data for inserting in left of "<<data;
  root->left=buildtree(root->left);
  cout<<"enter data for inserting in right of "<<data;
  root->right=buildtree(root->right);
  return root;
}

void inorder(node *root){
  //base case
  if(root==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void preorder(node *root){
  //base case
  if(root==NULL){
    return;
  }
  
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(node *root){
  //base case
  if(root==NULL){
    return;
  }
  
  
  postorder(root->left);
  postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
  node * root=NULL;

  //creating  a tree
  root=buildtree(root);

  cout<<"inorder traversal is: ";
  inorder(root);

  cout<<"preorder traversal is: ";
  preorder(root);

  cout<<"postorder traversal is: ";
  postorder(root);
}
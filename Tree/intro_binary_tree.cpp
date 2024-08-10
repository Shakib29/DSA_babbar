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
int main(){
  node * root=NULL;

  //creating  a tree
  root=buildtree(root);
}
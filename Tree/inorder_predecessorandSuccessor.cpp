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

node* maxval(node*root){
  node *temp=root;
  while (temp->right!=NULL)
  {
    temp=temp->right;
  }
  return temp;
}

pair<int,int> predeANDsuccessor(node *root,int key){
  node* temp=root;
  int pre=-1;
  int succ=-1;

  //find key
  while(temp->data!=key){
    if(temp->data>key){
      succ=temp->data;
      temp=temp->left;
    }else{
      pre=temp->data;
      temp=temp->right;
    }
  }
  //pre and succ

  //pre
  node *lefttree=temp->left;           //left me max value chahiye
  while(lefttree!=NULL){
    pre=lefttree->data;
    lefttree=lefttree->right;
  }

   //succ
  node *righttree=temp->right;      //right me min value chahiye
  while(righttree!=NULL){
    succ=righttree->data;
    righttree=righttree->left;
  }
  pair<int,int> ans=make_pair(pre,succ);
  return ans;
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


    return 0;
    
 
} 
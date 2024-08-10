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


void inorder(node *root,vector<int> &in){
  //base case
  if(root==NULL){
    return;
  }
  inorder(root->left,in);
  in.push_back(root->data);
  inorder(root->right,in);
}
bool gettarget(node*root,int target){
  vector<int> in;
  //inorder=>sorted value
   inorder(root, in);
  int i=0,j=in.size()-1;
  while(i<j){
  int sum=in[i]+in[j];

  if(sum==target){
  return true;
  }
  else if(sum>target){
  j--;
  }
  else{
  i++;
  }
  }
  return false;
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

     

      if(gettarget(root,10000)){
        cout<<"target found";
      }else{
        cout<<"target not found";
      }
    return 0;
    
 
} 
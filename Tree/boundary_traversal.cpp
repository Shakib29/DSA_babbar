#include <iostream>
#include <vector>
#include <queue>

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

void traverleft(node *root,vector <int>&ans){
  if((root==NULL)||(root->left==NULL&&root->right==NULL)){
  return;
  }
   ans.push_back(root->data);
   if(root->left!=NULL){
   traverleft(root->left,ans);
   }else{
    traverleft(root->right,ans);
   }
}

void traverleaf(node *root,vector<int> &ans){
  if(root==NULL){
    return;
  }
  if((root->left==NULL)&&(root->right==NULL)){
    ans.push_back(root->data);
    return;
  }
  traverleaf(root->left,ans);
    traverleaf(root->right,ans);

}

void traverseright(node *root,vector <int> &ans){
  if((root==NULL)||(root->left==NULL&&root->right==NULL)){
    return;
  }
  if(root->right!=NULL){
    traverseright(root->right,ans);
  }else{  
    traverseright(root->left,ans);
  }
  //wapas agye
  ans.push_back(root->data);

}

vector<int> boundary(node *root){
  vector<int> ans;
  if(root==NULL){
    return ans;
  }
  ans.push_back(root->data);

  //traverse left part 
  traverleft(root->left,ans);

  //traverse leaf node
  traverleaf(root->left,ans);    //for left subtree
   traverleaf(root->right,ans);    //for right subtree

  //traverse right part
  traverseright(root->right,ans);
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
   vector<int> result = boundary(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

 
}
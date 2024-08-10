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

void solve(node *root,vector<int> &ans,int level){
  if(root==NULL)
  return  ;

  //we have found a new level
  if(level==ans.size())
  ans.push_back(root->data);

  
     solve(root->right,ans,level+1);
     solve(root->left,ans,level+1);

}
vector<int> rightview(node *root){
vector<int> ans;
solve(root,ans,0);
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
   vector<int> result = rightview(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

 
}
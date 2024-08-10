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
vector<int> bottomview(node *root){
  vector<int> ans;
  if(root==NULL){
    return ans;
  }
  map<int,int> topnode;
   queue<pair<node*,int>> q;

   q.push(make_pair(root,0));

   while(!q.empty()){
    pair<node*,int> temp=q.front();
    q.pop();
    node *frontnode=temp.first;
    int hd=temp.second;

    //if 1 value is present  for  hd then do nothing
   
      topnode[hd]=frontnode->data;
    
    if(frontnode->left){
      q.push(make_pair(frontnode->left,hd-1));
    }
    if(frontnode->right){
      q.push(make_pair(frontnode->right,hd+1));
    }
   }
   for(auto i:topnode){
    ans.push_back(i.second);
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
   vector<int> result = bottomview(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

 
}
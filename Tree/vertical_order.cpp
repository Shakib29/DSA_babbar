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
vector<int> verticalorder(node *root){
  map <int ,map<int,vector<int>>> nodes;
 queue <pair<node*,pair<int,int>>> q;
vector<int> ans;
if(root==NULL){
  return ans;
}
q.push(make_pair(root,make_pair(0,0)));
while(!q.empty())
{
  pair<node*,pair<int,int>> temp=q.front();
  q.pop( );
   node* frontnode=temp.first;
     int hd=temp.second.first;
     int lvl=temp.second.second;

     nodes[hd][lvl].push_back(frontnode->data);
     if(frontnode->left){
      q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));

     }
     if(frontnode->right){
      q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
      
     }
}
for(auto i:nodes){
  for(auto j:i.second){
    for(auto k:j.second){
      ans.push_back(k);
    }
  }
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
   vector<int> result = verticalorder(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

 
}
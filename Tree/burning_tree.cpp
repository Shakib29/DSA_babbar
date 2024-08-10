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

node * create_parent_mapping(node * root,map<node *,node*>&nodetoparent,int target){
node* res=NULL;
queue<node*> q;
q.push(root);
nodetoparent[root]=NULL;
while(!q.empty()){
  node * front=q.front();
  q.pop();

  if(front->data==target){
    res=front;
  }

  if(front->left){
    nodetoparent[front->left]=front;
    q.push(front->left);
  }
  if(front->right){
    nodetoparent[front->right]=front;
    q.push(front->right);
  }
}
return res;
}
int burn_tree(node * root,map<node *,node*>&nodetoparent){
     map<node *,bool> visited;
     queue<node *> q;
     q.push(root);
     visited[root]=1;

     int time=0;

     while(!q.empty()){
      bool flag=0;
      int size=q.size();
      for(int i=0;i<size;i++){
        node *front=q.front();
        q.pop();

        if(front->left && !visited[front->left]){
          flag=1;
          q.push(front->left);
          visited[front->left]=1;
        }
         if(front->right && !visited[front->right]){
          flag=1;
          q.push(front->right);
          visited[front->right]=1;
        }
         if(nodetoparent[front] && !visited[nodetoparent[front]]){
          flag=1;
          q.push(nodetoparent[front]);
          visited[nodetoparent[front]]=1;
        }
      }
      if(flag==1){
        time++;
      }
     }
     return time;
}

int min_time(node *root,int target){
 //algo
 //1 creating a node to parent mapping
 //2 find target node
 //3burning tree in min time
int time=0;
map<node*,node*> nodetoparent;
node *targetnode=create_parent_mapping(root,nodetoparent,target);

time=burn_tree(targetnode,nodetoparent);

return time;
}



int main()
{
 
 // Creating a sample binary tree
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);

  int target = 5; // Specify the target node value
  cout << "Minimum time to burn the tree from node " << target << " is: " << min_time(root, target) << " units." << endl;

  return 0;





   

 
}
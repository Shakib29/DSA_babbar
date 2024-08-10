#include<iostream>
#include<queue>
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

node * buildfromlv(node * root){
  queue<node *> q;
  cout<<"enter data for root "<<endl;
  int data;
  cin>>data;
  root =new node(data);
  q.push(root);

  while(!q.empty()){
   node *temp=q.front();
   q.pop();
   cout<<"enter data for left data "<<temp->data<<endl;
   int leftdata;
   cin>>leftdata;

   if(leftdata!=-1){
    temp->left=new node(leftdata);
    q.push(temp->left);
   }

    cout<<"enter data for right data "<<temp->data<<endl;
   int rightdata;
   cin>>rightdata;

   if(rightdata!=-1){
    temp->right=new node(rightdata);
    q.push(temp->right);
   }
  }

}

int main(){
  node * root=NULL;

  //creating  a tree
  
  buildfromlv(root);
  //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
  root=buildtree(root);
}
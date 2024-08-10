#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node * next;

    node(int d){
     this->data=d;
     this->next=NULL;
    }
   
};
node* reverse_k_groups(node* head,int k){
  if(head==NULL){
    return NULL;
  }
  // 1 step =>reverse first k nodes
  node*prev=NULL;
  node* curr=head;
  node* forward=NULL;
  int count=0;
  while (curr!=NULL&&count<k)
  {
      forward=curr->next;
      curr->next=prev;
      prev=curr;
      curr=forward;
      count++;
  }
  // step 2=>recursion dekhlega
  if(forward!=NULL){
    head->next=reverse_k_groups(forward,k);

  } 
  return prev;
  
}

 void insert(node*&tail,int d){
        node * newnode=new node(d);
        tail->next=newnode;
        tail=tail->next;
    }
    void print(node *&head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
int main(){
node* newnode=new node(1);
node * head=newnode;
node* tail=newnode;
insert(tail,2);
// print(head);
insert(tail,3);
// print(head);
insert(tail,4);
print(head);
  head= reverse_k_groups(head,2);
  print(head);
  }
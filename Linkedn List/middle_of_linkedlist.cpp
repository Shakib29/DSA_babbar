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
//first approach
// int find_length(node * head){
//     int len=0;
//     while(head!=NULL){
//         len++;
//         head=head->next;
//     }
//     return len;
// }
// node *findmiddlenode(node*&head){
//     int len=find_length(head);
//     int ans=(len/2);
//     node* temp=head;
//     int cnt=0;
//     while(cnt<ans){
//         cnt++;
//         temp=temp->next;
//     }
//     return temp;
// }

//2nd approach

node *findmiddlenode(node *&head){
if(head==NULL||head->next==NULL){    //1 or 2 element in list
return head;
}
node *slow=head;


node *fast=head->next;
while(fast != NULL && fast->next != NULL){
     fast = fast->next;
     if(fast->next!=NULL){
        fast=fast->next;
     }
        slow = slow->next;
}
return slow;
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
  node* middle = findmiddlenode(head);
    cout << "Middle node data: " << middle->data << endl;
}
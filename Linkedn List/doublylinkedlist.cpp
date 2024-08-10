#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * prev;
    node * next;

    node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
     ~node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

void insertatbegin(node* &head,node *&tail,int d){
    if(head==NULL){
        node*temp=new node(d);
        head=temp;
        tail=temp;
        return;
    }
 node* newnode=new node(d);
 head->prev=newnode;
 newnode->next=head;
 head=newnode;
}

void insertatend(node*&head,node* &tail,int d){
    if(tail==NULL){
        node* temp=new node(d);
        head=temp;
        tail=temp;
        return;
    }
 node* newnode=new node(d);
 tail->next=newnode;
 newnode->prev=tail;
 tail=newnode;

}

void insertatpos(node *&head,node*&tail,int pos,int d){
 if(pos==1){
    insertatbegin(head,tail,d);
    return;
 }
 node * temp=head;
 
 int count=1;
 while(count<pos-1){
    count++;
    temp=temp->next;
 }
 if(temp->next==NULL){
    insertatend(head,tail,d);
    return;
 }
 node *newnode=new node(d);
 
 newnode->next=temp->next;
 temp->next->prev=newnode;
 temp->next=newnode;
 newnode->prev=temp;
}

void deletion(node *&head,node*&tail,int pos){
    if(pos==1){
        node *temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }else{
     node *curr=head;
     node *prev=NULL;
    int cnt=1;
    while(cnt<pos){
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    curr->prev=NULL;
     prev->next=curr->next;
    //  curr->next->prev=prev;
     curr->next=NULL;
     delete curr;





    }


}

void print(node * &head){
    node *temp=head;
    while(temp!=NULL){
        cout<<" "<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}

int getlength(node * &head){
    int length=0;
    node *temp=head;
    while(temp!=NULL){
      length++;
        temp=temp->next;
    }
    return length;
}

int main(){
//   node *node1=new node(5);
  node *head=NULL;
    node *tail=NULL;
    // print(head);
    // cout<<getlength(head);

insertatbegin(head,tail,4);
print(head);

insertatend(head,tail,6);
print(head);

insertatpos(head,tail,2,7);
print(head);

deletion(head,tail,2);
print(head);
}
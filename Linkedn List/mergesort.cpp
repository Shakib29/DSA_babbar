#include <iostream>
#include<vector>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data) // constructor
    {
        this->data = data;
        this->next = NULL;
    }

    ~node(){                     //destructor
        int value=this->data;
          //Free Memory
          if(this->next!=NULL){
            delete next;
            this->next=NULL;
          }
        //    cout << "Deleting node with data: " << value;
        }
};

void InsertAtHead(node *&head, int d)     //insert at beginning
{
    node *temp = new node(d); // creation of new node
    temp->next = head;
    head = temp;
}

void InsertAtTail(node *&tail, int d)
{
    node *temp = new node(d); // creation of new node
    tail->next = temp;
    tail = tail->next;
}

void InsertAtPos(node *&tail, node *&head, int pos, int d)
{
    if (pos == 1)
    {
        InsertAtHead(head, d);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // inserting at end
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    node *newnode = new node(d); // creation of new node
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletion(node *&head,int pos){
   //deletion at the beginning
   if(pos==1){
    node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;                 //free memory node
   }else{
    // deleting node in middle or last
    node *curr=head;
    node *prev=NULL;
    int cnt=1;
    while(cnt <pos){
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;

   }


}



void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
 
node* merge(node*&left,node*&right){
    if(left==NULL)
    return right;

    if(right==NULL)
    return left;

    node*ans=new node(-1);
    node*temp=ans;
    while(left!=NULL&&right!=NULL){
        if(left->data<right->data){
         temp->next=left;
        
         left=left->next;
        }else{
         temp->next=right;
        
         right=right->next;
        }
         temp = temp->next;
    }
    while(left!=NULL){
         temp->next=left;
       
         left=left->next;
         temp = temp->next;
    }
    while(right!=NULL){
         temp->next=right;
        
         right=right->next;
         temp = temp->next;
    }
    ans=ans->next;
    return ans;
}


node*findmiddle(node*&head)
{
    node*slow=head;
    node*fast=head->next;
    int count=0;
    while(fast!=NULL&&fast->next!=NULL){
     fast=fast->next->next;
     slow=slow->next;
    }
    return slow;
}

node* mergesort(node*&head){
 if(head==NULL||head->next==NULL){
    return head;
 }
 node*mid=findmiddle(head);
    node*left=head;
    node *right=mid->next;
    mid->next=NULL;
    left=mergesort(left);
    right=mergesort(right);
    node*result=merge(left,right);
    return result;

}

int main()
{ // creation of new node
    node *node1 = new node(6);
    

    // head pointed to node 1
    node *head = node1;

    // tail pointed to node 1,since now there is only one element
    node *tail = node1;

    InsertAtTail(tail, 9);
    // print(head);
    cout << endl;

    // InsertAtPos(tail, head, 3, 2);
    InsertAtTail(tail,2);
    InsertAtTail(tail, 7);
    
    InsertAtTail(tail, 8);
    
    InsertAtTail(tail, 4);
    // print(head);

    // cout << endl
    //      << "head->"  << head->data << endl;
    // cout << "tail->" << tail->data << endl;
    //    deletion(head,2);
       cout<<endl;

       print(head);
       cout<<endl;
    //    tail->next=head->next;
     
      node*result=mergesort(head);
      cout<<"printing sorted list";
      cout<<endl;
      print(result);
}

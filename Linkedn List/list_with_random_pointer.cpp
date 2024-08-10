#include <iostream>
#include<unordered_map>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node* random;
    node(int data) // constructor
    {
        this->data = data;
        this->next = NULL;
        this->random=NULL;
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
 void insertattaill(node*&head,node*&tail,int d){
 node*temp=new node(d);
 if(head==NULL){
    head=temp;
    tail=temp;
    return;
 }else{
    tail->next=temp;
    tail=temp;
 }
 }

node*copylist(node * &head){
    //1.create a clone list
    node*clonehead=NULL;
    node *clonetail=NULL;
   node *temp=head;
   while(temp!=NULL){
    insertattaill(clonehead,clonetail,temp->data);
    temp=temp->next;
   }
   //2.Create a map
   unordered_map<node*,node*> oldtonewnode;
   temp=head;
   node*temp2=clonehead;
   while(temp!=NULL&&temp2!=NULL){
    oldtonewnode[temp]=temp2;
    temp=temp->next;
    temp2=temp2->next;
   }
   temp=head;
   temp2=clonehead;
   while(temp!=NULL){
     temp2->random=oldtonewnode[temp->random];
     temp=temp->next;
    temp2=temp2->next;
   }
  return clonehead;
}

int main()
{ // creation of new node
    node *node1 = new node(1);
    

    // head pointed to node 1
    node *head = node1;

    // tail pointed to node 1,since now there is only one element
    node *tail = node1;

    InsertAtTail(tail, 0);
    // print(head);
    cout << endl;

    // InsertAtPos(tail, head, 3, 2);
    InsertAtTail(tail,2);
    InsertAtTail(tail, 2);
    
    InsertAtTail(tail, 0);
    
    InsertAtTail(tail, 1);
    // print(head);

    // cout << endl
    //      << "head->"  << head->data << endl;
    // cout << "tail->" << tail->data << endl;
    //    deletion(head,2);
       cout<<endl;
       print(head);
    
      
}

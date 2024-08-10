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
 
//approach 1 jisme ek array me list data copy karke ,same array wala logic lagege
// bool find_palindrome(vector<int> arr){
//     int s=0;
//     int e=arr.size()-1;
//     while(s<e){
//         if(arr[s]!=arr[e]){
//             return false;
//         }
//         s++;
//         e--;
//     }
//     return true;
// }
// bool palindromesolution(node *&head){   //main
// vector <int>arr ;
// node* temp=head;
// while (temp!=NULL){
//     arr.push_back(temp->data);
//     temp=temp->next;
// }
//  return find_palindrome(arr);
// }

//approach 2 
//1)find mid of list   2)reverse list from mid+1 to last node 3)compare 0tomid and mid+1 to n

node *getmid(node *&head){
    node*slow=head;
    node *fast=head->next;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;


}
node * reverse(node * head){
    node * curr=head;
    node * prev=NULL;
    node * forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        curr=prev;
       curr= forward;
    }
    return prev;

}
 bool palindromesolution(node *&head){
if(head->next=NULL){
        return 1;
    }
    // step 1=>find mid
node * mid=getmid(head);

//step 2=> reverse list after middle
node *temp=mid->next;
mid->next=reverse(temp);

//step 3=>compare both halves
node * head1=head;
node * head2=mid->next;
while(head2!=NULL){
    if(head1->data!=head2->data){
        return false;
    }
    head1++;
    head2++;
}
//step 4=>repeat step 2
temp=mid->next;
mid->next=reverse(temp);

return true;
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
    //    tail->next=head->next;
       if(palindromesolution(head)){
        cout<<"it is a palindrome";
       }else{
        cout<<"it is not a palindrome";
       }
      
}

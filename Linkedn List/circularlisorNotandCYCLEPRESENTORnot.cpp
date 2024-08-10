#include <iostream>
#include <map>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << value << endl;
    }
};

void insertion(node *&tail, int element, int d)
{
    // assuming element is present in the list
    if (tail == NULL)
    { // list is empty
        node *newnode = new node(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // matlab element mil chuka hai
        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deletion(node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "list is empty";
        return;
    }
    else
    {
        node *prev = tail;
        node *curr = prev->next;
        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        if (curr == prev)
        { // 1 node
            tail = NULL;
        }
        else if (tail == curr)
        { //>=2 nodes
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
bool circularornot(node *&head)
{
    if (head == NULL)
    {
        cout << "list is empty";
        return true;
    }
    else if (head == head->next)
    {
        return true;
    }
    else
    {
        node *temp = head->next;
        while (temp != NULL && temp != head)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            return true;
        }
    }
}

bool loopdetect(node *&head)
{
    if (head == NULL)
    {
        return false;
    }
    map<node *, bool> visited;
    node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "loop is at => " << temp->data;
            return true; // cycle is present
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

void print(node *&tail)
{

    node *temp = tail;
    if (tail == NULL)
    {
        cout << "list is empty";
        return;
    }
    // cout<<tail->data<<" ";
    // while(tail->next!=temp){
    //     cout<<tail->data<<" ";
    //     tail=tail->next;
    // }
    // cout<<" ";
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    node *tail = NULL;
    insertion(tail, 5, 3);
    print(tail);
    insertion(tail, 3, 4);
    insertion(tail, 4, 5);
    insertion(tail, 5, 6);
    print(tail);
    // deletion(tail,3);
    // print(tail);
    if (circularornot(tail))
    {
        cout << "it has a loop";
    }
    else
    {
        cout << "not have a loop";
    }
}
#include <iostream>

// Definition of the singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to reverse the linked list
Node* reverseList(Node* &head) {
    Node* prev = nullptr;
    Node* current = head;
 

    while (current != nullptr) {
        Node* forward=current->next;
        current->next=prev;
        prev=current;
         current=forward;
    }
    return prev;
}

int main() {
    // Creating a simple linked list 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original list: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    std::cout << "Reversed list: ";
    printList(head);

    return 0;
}

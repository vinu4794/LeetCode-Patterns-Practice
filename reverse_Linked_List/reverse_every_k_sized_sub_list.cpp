#include<iostream>
using namespace std;

class Node {
    public:
        int value;
        Node *next;

        Node(int value) 
        {
            this->value = value;
            this->next = nullptr;
        }
};

Node* reverseEveryKSizedSubList(Node *head, int k)
{
    // First Run 1 to k
    Node *previous = nullptr;
    Node *current = head;
    Node *temp = nullptr;
    Node *newHead = nullptr, *lastPrev = nullptr;
    Node *og_current = nullptr;
    og_current = current;

    while (current != nullptr) {
        Node *ogPrev = og_current;        
        
        for (int i = 0; i < k; i++) {
            if (current) {
                temp = current->next;
                current->next = previous;
                lastPrev = previous;
                previous = current;
                current = temp;
            }
        }
        newHead = previous;  // Head of Partial linked list

        if (ogPrev)
            ogPrev->next = newHead;
        
        if (current)
            og_current->next = current;

        if (og_current == head) {
            head = newHead;
        }
    }
    return head;
}

void printLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr) {
        cout << current->value;
        current = current->next;
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 3;
    head = reverseEveryKSizedSubList(head, k);
    printLinkedList(head);
    return 0;
}
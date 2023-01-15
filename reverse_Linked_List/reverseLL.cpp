#include<iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node(int value) 
        {
            this->value = value;
            this->next = nullptr;
        }
};

Node* reverseLinkedList(Node* head)
{
    Node *previous = nullptr;
    Node *current = head;
    Node *temp;

    while (current != nullptr) {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    head = previous;

    return head;
}

void printLinkedList(Node *head)
{
    Node *currentNode = head;
    while(currentNode != nullptr) {
        cout << currentNode->value << " ";
        currentNode = currentNode->next;
    }
}

int main()
{
    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(10);

    head = reverseLinkedList(head);

    printLinkedList(head);
    return 0;
}
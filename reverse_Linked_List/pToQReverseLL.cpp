#include <iostream>

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

Node* pToQReverseLinkedList(Node *head, int p, int q)
{
    int numberOfIterations = q - p + 1;

    Node *current = head;

    // Reach pth Node
    Node *previous = nullptr;
    for (int i = 0; i < p - 1; i++) {
        previous = current;
        current = current->next;
    }
    
    Node *temp = nullptr, *newHead = nullptr;
    Node *ogPrev = previous;
    Node *og_current = current;

    previous = nullptr;

    for (int i = 0; i < numberOfIterations; i++) {
        temp = current->next;
        
        current->next = previous;
        
        previous = current;
        current = temp;
    }
    newHead = previous;  
    if (ogPrev)
        ogPrev->next = newHead;
    
    if (current)
        og_current->next = current;

    if (og_current == head) {
        head = newHead;
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

    int p = 1;
    int q = 3;

    head = pToQReverseLinkedList(head, p, q);
    printLinkedList(head);
    return 0;
}
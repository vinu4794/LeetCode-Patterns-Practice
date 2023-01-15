#include<iostream>
using namespace std;

class Node {
    public:
        int value;
        Node *next;
    public:
        Node(int value) 
        {
            this->value = value;
            this->next = nullptr;
        }
};

Node* getCycleStartNode(Node *head)
{
    Node *slowPtr = head;
    Node *fastPtr = head;
    bool loopExists = false;

    while(fastPtr != nullptr && fastPtr->next != nullptr) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr) {
            loopExists = true;
            break;
        }
    }

    if (loopExists) {
        slowPtr = head;

        while(slowPtr != fastPtr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        return slowPtr;
    }
    else {
        return nullptr;
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
    head->next->next->next->next->next->next->next->next = head->next->next->next->next; // Node 5
    
    Node *outputNode = getCycleStartNode(head);
    cout << "Start of cycle is: " << outputNode->value;
    return 0;
}

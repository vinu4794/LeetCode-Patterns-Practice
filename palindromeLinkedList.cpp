#include<iostream>

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

Node* findMiddleLL(Node *head)
{
    Node *slowPtr = head;
    Node *fastPtr = head;

    while(fastPtr != nullptr && fastPtr->next != nullptr) 
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr;
}

Node *reverseLL(Node *head)
{
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        return head; // NEW HEAD of reversed LL
    }

    Node *secondElement = head->next;

    head->next = nullptr;
    Node *newLL = reverseLL(secondElement); // Presere the end ptr as new HEAD

    secondElement->next = head;    

    return newLL;
}


bool isPalindromeLL(Node *head)
{
    Node *middleNode = findMiddleLL(head);
    Node *head2 = reverseLL(middleNode);

    Node *ptr1 = head;
    Node *ptr2 = head2;

    bool isPalindrome = true;

    while(ptr1 != nullptr && ptr2 != nullptr) {
        if (ptr1->value != ptr2->value) {
            isPalindrome = false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (ptr1 == nullptr && ptr2 == nullptr && isPalindrome) {
        return true;
    }
    else
        return false;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(9);
    
    bool out = isPalindromeLL(head);
    std::cout << "IS Palindrome " << out;

    return 0;
}
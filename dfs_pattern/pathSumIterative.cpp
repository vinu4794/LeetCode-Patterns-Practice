#include<iostream>
#include<stack>

using namespace std;

class Node {
    public:
        int value;
        Node *left;
        Node *right;

        Node(int value)
        {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
};

int pathSum(Node *head)
{
    int sum = 0;

    stack<Node*> stack1;
    stack1.push(head);

    while (!stack1.empty()) {
        Node *currentNode = stack1.top();
        stack1.pop();

        if (currentNode) {
            cout << currentNode->value;
        }

        if (currentNode->left) {
            stack1.push(currentNode->left);            
        } 

        if (currentNode->right) {
            stack1.push(currentNode->right);
        }

    }

    return sum;
}

int main()
{
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);

    head->left->left = new Node(4);
    head->left->right  = new Node(5);

    head->right->left = new Node(6);
    head->right->right = new Node(7);

    pathSum(head);

    return 0;
}
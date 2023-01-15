#include<iostream>

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

bool isLeaf(Node *head)
{
    if (!(head->left) && !(head->right)) {
        return true;
    }
    return false;
}

int pathSum(Node *head, int targetSum)
{
    targetSum -= head->value;

    if (isLeaf(head)) {
        if (targetSum == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isPathSumFound = false;

    if (head->left) {
        isPathSumFound = pathSum(head->left, targetSum);
    }

    if (!isPathSumFound) {
        if (head->right) {
            isPathSumFound = pathSum(head->right, targetSum);
        }
    }
    else {
        return true;
    }
    return isPathSumFound;
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

    bool out = pathSum(head, 8);
    cout << " Has Path Sum Bool : " << out;

    return 0;
}
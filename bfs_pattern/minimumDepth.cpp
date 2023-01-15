#include<iostream>
#include <queue>
#include<limits>

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

int computeMinDepthBinaryTree(Node *head)
{
    int minDepth = numeric_limits<int>::max();

    queue<Node*> q1;
    q1.push(head);
    q1.push(nullptr);

    int level = 1;

    while (!q1.empty()) {
        Node *currentNode = q1.front();
        q1.pop();

        if (!currentNode) {
            level++;

            if (!q1.empty()) {
                q1.push(nullptr);
            }
        }
        else {

            // isLeaf Node
            if (!(currentNode->left) && !(currentNode->right)) {
                minDepth = min(minDepth, level);
            }
            else {

                if (currentNode->left) {
                    q1.push(currentNode->left);
                }

                if (currentNode->right) {
                    q1.push(currentNode->right);
                }
            }
        }

    }


    return minDepth;
}

int main()
{
    // Construct Binary Tree
    Node *head = new Node(12);
    head->left = new Node(7);
    head->right = new Node(1);

    head->left->left = new Node(9);

    head->right->left = new Node(10);
    head->right->right = new Node(5);

    head->right->left->left = new Node(11);

    int minDepth = computeMinDepthBinaryTree(head);
    cout << "Min Depth is: " << minDepth;
    return 0;
}
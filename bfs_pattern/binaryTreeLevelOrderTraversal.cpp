#include<iostream>
#include<vector>
#include <queue>
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

vector<vector<int>> bfs(Node *head)
{
    queue<Node*> queue1;
    stack<vector<int>> stack1;

    vector<vector<int>> bfsOrder;

    queue1.push(head);
    queue1.push(nullptr);

    vector<int> headValue = {head->value};
    bfsOrder.push_back(headValue);
    stack1.push(headValue);

    int level = 0;
    vector<int> currentLevelElements = {};

    while(!queue1.empty()) {
        Node *currentNode = queue1.front();
        // if (currentNode) {
        //     cout << currentNode->value;
        // }
        queue1.pop();

        // Level Completed
        if (currentNode == nullptr) {
            bfsOrder.push_back(currentLevelElements);
            stack1.push(currentLevelElements);
            currentLevelElements = {};
            level++;            

            if (!queue1.empty()) {
                queue1.push(nullptr);
            }
        }
        else {
            if (currentNode->left) {
                queue1.push(currentNode->left);
                currentLevelElements.push_back(currentNode->left->value);
            }
            if (currentNode->right) {
                queue1.push(currentNode->right);
                currentLevelElements.push_back(currentNode->right->value);
            }
        }
    }

    vector<vector<int>> reverseLevelOrder;
    while(!stack1.empty()) {
        reverseLevelOrder.push_back(stack1.top());
        stack1.pop();
    }
    return reverseLevelOrder;
}

int main()
{
    // Construct Binary Tree
    Node *head = new Node(12);
    head->left = new Node(7);
    head->right = new Node(1);

    head->left->left = new Node(9);
    head->left->right = new Node(10);

    head->right->left = new Node(5);

    // Level-Order Traversal
    vector<vector<int>> out = bfs(head);

    // Print Traversal
    for (auto iterator1:out) {
        for (auto iterator2:iterator1) {
            cout << iterator2 << " ";
        }
        cout << endl;
    }

    return 0;
}
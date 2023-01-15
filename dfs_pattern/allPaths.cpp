#include<iostream>
#include<vector>

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

vector<vector<int>> allPaths = {};
vector<int> currentPath = {};

void computePathsUtil(Node *head, int targetSum)
{
    if (!head) {
        return;
    }
    currentPath.push_back(head->value);

    if (isLeaf(head) && targetSum == head->value) {
        allPaths.push_back(currentPath);
    }
    else {    
        computePathsUtil(head->left, targetSum-head->value);
        computePathsUtil(head->right, targetSum-head->value);
    }
    currentPath.pop_back();
}

vector<vector<int>> getAllPaths(Node *head, int targetSum)
{
    computePathsUtil(head, targetSum);
    return allPaths;
}



int main()
{
    Node *head = new Node(1);
    head->left = new Node(7);
    head->right = new Node(9);

    head->left->left = new Node(4);
    head->left->right  = new Node(5);

    head->right->left = new Node(2);
    head->right->right = new Node(7);

   vector<vector<int>> out = getAllPaths(head, 12);
    
    for (int i = 0; i < out.size(); i++) {
        for (int j = 0; j < out[i].size(); j++) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#include<iostream>
#include<vector>
#include <cmath>

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

vector<int> allPaths = {};
vector<int> currentPath = {};

void computePathsUtil(Node *head)
{
    if (!head) {
        return;
    }
    currentPath.push_back(head->value);

    if (isLeaf(head)) {
        int n = currentPath.size();
        int finalNum = 0;
        
        for (int i = 0; i < currentPath.size(); i++) {
            finalNum = finalNum + pow(10,n-1) * currentPath[i];   
            n--; 
        }
        allPaths.push_back(finalNum);
    }
    else {    
        computePathsUtil(head->left);
        computePathsUtil(head->right);
    }
    currentPath.pop_back();
}

int sumAllPaths(Node *head)
{
   computePathsUtil(head);
    
    int sum = 0;

    for (auto iter:allPaths) {
        sum += iter;
    }
    return sum;
}



int main()
{
    Node *head = new Node(1);
    head->left = new Node(0);
    head->right = new Node(1);
    head->left->left = new Node(1);

    head->right->left = new Node(6);
    head->right->right = new Node(5);

    int out = sumAllPaths(head);
    cout << out;

    return 0;
}
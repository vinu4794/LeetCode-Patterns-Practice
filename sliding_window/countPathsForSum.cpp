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

class CountPathsForSum
{
    public:
        static int getCountPaths(Node *head, int targetSum)
        {
            vector<int> currentPath;
            return countPathsRecursion(head, targetSum, currentPath);
        }
    private:
        static int countPathsRecursion(Node *currentNode, int targetSum, vector<int> &currentPath) 
        {
            if (!currentNode) {
                return 0;
            }

            // Add current Node
            currentPath.push_back(currentNode->value);

            int pathSum = 0, pathCount = 0;

            for (vector<int>::reverse_iterator itr = currentPath.rbegin(); itr != currentPath.rend(); itr++) {
                pathSum += *itr;

                if (pathSum == targetSum) {
                    pathCount++;
                }
            }

            pathCount += countPathsRecursion(currentNode->left, targetSum, currentPath);
            pathCount += countPathsRecursion(currentNode->right, targetSum, currentPath);

            currentPath.pop_back();
            return pathCount;

        }
};

int main()
{
    Node *head = new Node(1);
    head->left = new Node (7);
    head->right = new Node(9);

    head->left->left = new Node(6);
    head->left->right = new Node(5);

    head->right->left = new Node(2);
    head->right->right = new Node(3);

    int outCount = CountPathsForSum::getCountPaths(head, 12);
    cout << outCount;

    return 0;
}
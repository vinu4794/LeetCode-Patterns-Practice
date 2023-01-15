#include<iostream>
using namespace std;

class Node 
{
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



class HouseRobber3
{
    pair<int,int> dfs(Node *root)
    {
        pair<int,int> result;

        if(root == nullptr){
            result.first = 0;
            result.second = 0;
            return result;
        }
        
        pair<int,int> leftChildren = dfs(root->left); 
        pair<int,int> rightChildren = dfs(root->right);

        int not_node = max(leftChildren.first, leftChildren.second) + max(rightChildren.first, rightChildren.second); 
        int node = root->value + leftChildren.second + rightChildren.second;

        result.first = node;
        result.second = not_node;
        return result;
    }

    public:
        int compute(Node *root)
        {
            pair<int,int> output;
            output = dfs(root);
            return max(output.first,output.second);
        }
};

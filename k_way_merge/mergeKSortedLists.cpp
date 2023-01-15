#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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

class MergeKSortedLists {
    public:
        struct valueCompare {
            bool operator()(const Node *x, const Node *y)
            {
                return (x->value > y->value);
            }
        };
        
        static Node* compute(const vector<Node*> &linkedLists)
        {
            priority_queue<Node*, vector<Node*>, valueCompare> minHeap;
            Node *newHead = nullptr;

            for (auto root:linkedLists) {
                minHeap.push(root);
            }

            // First min element.
            Node *currentMinElement = minHeap.top();
            minHeap.pop();
            minHeap.push(currentMinElement->next);

            newHead = currentMinElement;
            Node *tail = newHead;

            while(!minHeap.empty()) {
                currentMinElement = minHeap.top();
                minHeap.pop();

                tail->next = currentMinElement;
                tail = tail->next;
                if (currentMinElement->next != nullptr) {
                    minHeap.push(currentMinElement->next);
                }
            }

            return newHead;
        }

};

int main(int argc, char **argv)
{
    Node *l1 = new Node(2);
    l1->next = new Node(6);
    l1->next->next = new Node(8);

    Node *l2 = new Node(3);
    l2->next = new Node(6);
    l2->next->next = new Node(7);

    Node *l3 = new Node(1);
    l3->next = new Node(3);
    l3->next->next = new Node(4);

    Node *result = MergeKSortedLists::compute(vector<Node*>{l1,l2,l3});

    while(result != nullptr) {
        cout << result->value << " ";
        result = result->next;
    }
    return 0;
}
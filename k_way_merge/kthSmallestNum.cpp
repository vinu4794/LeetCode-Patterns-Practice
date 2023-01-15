using namespace std;

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class KthSmallestNumInSortedArray
{
    public:
        struct valueCompare
        {
            bool operator()(const pair<int, pair<int,int>> &x, pair<int, pair<int,int>> &y)
            {
                return (x.first > y.first);
            }
        };
        static int compute(const vector<vector<int>> &arrs, int k)
        {
            
            priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, valueCompare> minHeap;

            for (int i = 0; i < arrs.size(); i++) {
                minHeap.push(make_pair(arrs[i][0], make_pair(i,0)));
            }

            int numberCount = 0, result = 0;

            while(!minHeap.empty()) {
                auto node = minHeap.top();
                minHeap.pop();
                result = node.first;

                if (++numberCount == k) {
                    break;
                }

                node.second.second++;

                // If next inde exists, push ele into heap
                int sizeOfArr = arrs[node.second.first].size();

                if (sizeOfArr > node.second.second) {
                    int arrNum = node.second.first;
                    int idx = node.second.second;
                    node.first = arrs[arrNum][idx];
                    minHeap.push(node);
                }
            }

            return result;
        }
};

int main(int argc, char **argv)
{
    vector<vector<int>> arrs = {{2,6,8}, {3,6,7}, {1,3,4}};
    int result = KthSmallestNumInSortedArray::compute(arrs,5);
    cout << result;
    return 0;
}
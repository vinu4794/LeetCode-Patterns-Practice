#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TopKNumbers {
    public:
        static vector<int> compute(const vector<int> &arr, int k)
        {
            vector<int> result;
            priority_queue<int, vector<int>, greater<int>> minHeap;

            for (int i = 0; i < k; i++) {
                minHeap.push(arr[i]);
            }

            int n = arr.size();

            for (int i = k; i < n; i++) {
                int rootElement = minHeap.top();

                if (arr[i] > rootElement) {
                    minHeap.pop();
                    minHeap.push(arr[i]);
                }
            }

            for (int i = k; i > 0; i--) {
                result.push_back(minHeap.top());
                minHeap.pop();
            }

            return result;
        }
};

int main(int argc, char **argv)
{
    vector<int> inputArray = {3, 1, 5, 12, 2, 11};
    int k = 3;
    vector<int> out = TopKNumbers::compute(inputArray, k);

    for (auto num:out) {
        cout << num << " ";
    }

    return 0;
}

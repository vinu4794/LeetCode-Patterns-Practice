#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class ClosestKNumbers
{
    public:
        static vector<int> compute(vector<int> arr, int k, int x)
        {
            vector<int> result;

            priority_queue<int, vector<int>, greater<int>> minHeap;

            int n = arr.size();

            for (int i = 0; i < k; i++) {
                minHeap.push(arr[i]);
            }

            int currentDiff = 0;
            int rootDiff = 0;

            for (int i = k; i < n; i++) 
            {
                currentDiff = abs(arr[i] - x);
                rootDiff = abs(minHeap.top() - x);

                if (currentDiff < rootDiff) {
                    minHeap.pop();
                    minHeap.push(arr[i]);
                }
            }

            while(minHeap.size() > 0) {
                int ele = minHeap.top();
                result.push_back(ele);
                minHeap.pop();
            }
            return result;
        }
};

int main(int argc, char **argv)
{
    vector<int> inputArray = {2, 4, 5, 6, 9};
    int k = 3, x = 5;
    vector<int> out = ClosestKNumbers::compute(inputArray, k, x);

    for (auto num:out) {
        cout << num << ", ";
    }

    return 0;
}
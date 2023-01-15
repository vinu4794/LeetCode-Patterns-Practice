#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class MaxDistinctElements
{
    public:
        struct greaterThanComparator 
        {
            bool operator()(const pair<int,int> &x, const pair<int,int> &y)
            {
                return x.second > y.second;
            }
        };

        static int compute(const vector<int> &arr, int k)
        {
            vector<int> result;

            unordered_map<int,int> freqMap;

            int n = arr.size();
            int num;

            for (int i = 0; i < n; i++) {
                num = arr[i];
                freqMap[num]++;    
            }

            priority_queue<pair<int,int>,vector<pair<int,int>>, greaterThanComparator> minHeap;

            // minHeap now contains only nums with freq > 1
            for (auto entry:freqMap) {
                if (entry.second == 1) {
                    result.push_back(entry.first);
                }
                else {
                    minHeap.push(entry);
                }
            }

            // Remove only k elements
            pair<int,int> currentEntry;
            int numOfElementsRemoved = 0;
            for (int i = 0; i < k; i++) {
                if (minHeap.empty()) {
                    break;
                }
                currentEntry = minHeap.top();
                currentEntry.second--;
                numOfElementsRemoved++;

                if (currentEntry.second == 1) {
                    result.push_back(currentEntry.first);
                    minHeap.pop();
                }
            }

            if (numOfElementsRemoved < k) {
                while( numOfElementsRemoved != k) {
                    result.pop_back();
                    numOfElementsRemoved++;
                }
            }
            
            return result.size();
        }

};

int main(int argc, char **argv)
{
    vector<int> inputArray = {1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5};
    int k = 2;
    int out = MaxDistinctElements::compute(inputArray, k);
    cout << out;
    return 0;
}
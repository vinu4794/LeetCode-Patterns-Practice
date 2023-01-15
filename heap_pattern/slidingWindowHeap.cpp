#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class SlidingWindowHeap 
{
    public:
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        void insertNum(int num) 
        {
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            }
            else {
                minHeap.push(num);
            }

            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        double findMedian()
        {
            if (maxHeap.size() == minHeap.size()) {
                return (maxHeap.top() + minHeap.top()) /2;
            }
            
            return maxHeap.top();
        }

        vector<int> findMedianSubArrays(const vector<int> &arr, int k)
        {
            // Create output Arr containing medians
            vector<int> outArr(arr.size() - k + 1);

            // Push Elements into Heap.
            for (int i = 0; i < arr.size(); i++) {
                if (maxHeap.empty() || arr[i] <= maxHeap.top()) {
                    maxHeap.push(arr[i]);
                }
                else {
                    minHeap.push(arr[i]);
                }
                // rebalanceHeaps();

                // We need at least k elements in our wiindow to compute median
                if (i - k + 1 >= 0) {
                    if (maxHeap.size() == minHeap.size()) {
                        result[i-k+1] = (maxHeap.top() + minHeap.top())/2;
                    } else {
                        result[i-k+1] = maxHeap.top();
                    }

                int elementToBeRemoved = arr[i - k + 1];

                if (elementToBeRemoved <= maxHeap.top()) {
                    maxHeap.remove(elementToBeRemoved);
                }
                else {
                    minHeap.remove(elementToBeRemoved);
                }
                rebalanceHeaps();
                }
            }
            
            return outArr;
        }
};


int main()
{
    SlidingWindowHeap medianObj;
    medianObj.insertNum(3);
    medianObj.insertNum(1);
    cout << "Median is: " << medianObj.findMedian();

    return 0;
}
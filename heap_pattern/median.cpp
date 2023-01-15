#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class MedianUsingHeaps {
    public:
        // Define Max and Min Heaps
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        void insertNum(int num)
        {
            // If maxHeap is empty or num to be inserted is smaller than max heal top
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            }
            else {
                // Bigger number would go to the right to median. Thus min Heap
                minHeap.push(num);
            }

            // Balance out number of nodes in both Heaps if not equal,
            // or, max heap must have one more element.
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
                return ((maxHeap.top() + minHeap.top()) /2);
            }
            return maxHeap.top();
        }
        
};

int main()
{
    MedianUsingHeaps medianObj;
    medianObj.insertNum(3);
    medianObj.insertNum(1);
    cout << "Median is: " << medianObj.findMedian();


    return 0;
}
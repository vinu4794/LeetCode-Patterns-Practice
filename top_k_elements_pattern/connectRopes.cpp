#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class MinCostConnectRopes
{
    public:
        static int compute(const vector<int> ropeLengths)
        {
            priority_queue<int, vector<int>, greater<int>> minHeap;

            for (auto rope:ropeLengths) {
                minHeap.push(rope);
            }

            int result = 0;
            int currentRopeLength = 0;
            int firstElement = 0, secondElement = 0;

            while(minHeap.size() > 1) {
                firstElement  = minHeap.top();
                minHeap.pop();
                currentRopeLength = firstElement;                

                secondElement = minHeap.top();
                minHeap.pop();
                currentRopeLength += secondElement;                

                result += currentRopeLength;
                minHeap.push(currentRopeLength);
            }
            return result;
        }
};

int main(int argc, char **argv)
{
    int out = MinCostConnectRopes::compute(vector<int>{1,3,11,5,2});
    cout << out;

    return 0;
}
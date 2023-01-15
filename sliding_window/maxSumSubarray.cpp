#include<iostream>
#include<vector>
using namespace std;

int maxSumSubarray(int k, const vector<int>& arr)
{
    int maxSum = 0;
    int windowSum = 0;
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
        windowSum += arr[windowEnd];
        if(windowEnd >= k - 1) {
            maxSum = max(windowSum, maxSum);
            windowSum -= arr[windowStart];
            windowStart++;
        }
    }

    return maxSum;
}

int main()
{
    vector<int> inputVector = {2, 3, 4, 1, 5};
    int k = 2;
    int out = maxSumSubarray(k, inputVector);
    cout << " The maximum sum of any k-sized subarray is: " << out << endl;

    return 0;
}
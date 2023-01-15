#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int minLengthSubarrayWithTargetSum(int targetSum, const vector<int>& arr)
{
    int minLength = numeric_limits<int>::max();
    int windowStart = 0;
    int windowSum = 0;

    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
        windowSum += arr[windowEnd];

        while (windowSum >= targetSum) {
            minLength = min(minLength, windowEnd - windowStart + 1);

            // Shrink Window from start index
            windowSum -= arr[windowStart];
            windowStart++;
        }
    }

    // If minLength was not modified
    if (minLength == numeric_limits<int>::max()) {
        return 0;
    }
    else {
        return minLength;
    }
}

int main()
{
    vector<int> inputArr = {2, 1, 5, 2, 3, 2};
    int targetSum = 7;
    int out = minLengthSubarrayWithTargetSum(targetSum,inputArr);
    cout << "Min Length is: " << out << endl;
    return 0;
}
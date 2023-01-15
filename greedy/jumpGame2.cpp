#include<iostream>
#include<vector>
using namespace std;

class JumpGame2 
{
    public:
        int compute(const vector<int> &nums)
        {
            // We want to compute the minimum number of jumps to reach the last element
            int totalJumps = 0;

            // We make use of a window range to keep track of the indices that you can reach from the
            // current location.
            // For example: [2,3,1,1,4]
            // Here, for startIndex = 0, [3,1] is one such window since these are the values that can be
            // reached from the starting point.
            int windowStart = 0;
            int windowEnd = 0;

            // Keep making such windows until the last element is reached.
            // Again, a window signifies the values that you can reach from the current location
            while (windowEnd < nums.size() - 1) { // The while loop is less than (size - 1) since we need elements to jump to as well.
                int farthestIndex = 0;

                // Compute the farthest point you can jump to from each point in the window.
                // Keep track of only the farthest index you could have jumped to from any of the elements in the window
                for (int i = windowStart; i <= windowEnd; i++) {
                    farthestIndex = max(farthestIndex, i + nums[i]);
                }

                // The next or new window will be:
                // the end point of this window would be the farthest point you can jump to
                // At this point, we have already covered all elements in the current window, 
                // to have computed the farthest index. Thus start of the new window is windowEnd+1
                windowStart = windowEnd + 1;
                windowEnd = farthestIndex;
                totalJumps += 1;
            }
            return totalJumps;
        }
};

int main()
{
    vector<int> nums = {2,3,1,1,4};
    JumpGame2 jgObj;
    int res = jgObj.compute(nums);
    cout << res;

    return 0;
}
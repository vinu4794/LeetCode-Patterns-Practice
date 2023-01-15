#include<iostream>
#include<vector>

using namespace std;

class PartitionSet {
    public:
        int canPartition(const vector<int> &nums)
        {
            int sum = 0;

            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
            }

            int n = nums.size();

            vector<vector<bool>> dp(n, vector<bool>(sum/2 + 1, false));

            for (int i = 0; i < n; i++) {
                dp[i][0] = true;
            }

            for (int s = 0; s<= sum/2; s++) {
                dp[0][s] = (nums[0] == s ? true : false);
            }

            for (int i = 1; i<nums.size(); i++) {
                for (int s = 1; s <= sum/2; s++) {
                    if (dp[i-1][s]) {
                        dp[i][s] = dp[i-1][s];
                    }
                    else if (s >= nums[i]) {
                        dp[i][s] = dp[i-1][s-nums[i]];
                    }
                }
            }

            int sum1 = 0;

            for (int i = sum/2; i >= 0; i--) {
                if (dp[n-1][i] == true) {
                    sum1 = i;
                    break;
                }
            }

            int sum2 = sum - sum1;
            return abs(sum2-sum1);
        }
};

int main(int argc, char **argv)
{
    PartitionSet ps;
    vector<int> nums = {1,2,3,9};
    cout << ps.canPartition(nums);
    return 0;
}
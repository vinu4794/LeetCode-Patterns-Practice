bool CanPartitionArray(vector<int> arr)
{
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }

    if (sum % 2 != 0) {
        return false;
    }

    int n = arr.size();
    sum = sum/2;
    vector<vector<bool>> dp(n, vector<bool>(sum + 1));
    
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i<=sum; i++) {
        dp[0][i] = (arr[0] == i) ? true : false;
    }

    for (int i = 1; i < n; i++) {
        for (int currentSum = 1; currentSum <= sum; currentSum++) {
            if (dp[i-1][currentSum]) {
                dp[i][currentSum] = dp[i-1][currentSum];
            }
            else if (currentSum >= arr[i]) {
                dp[i][currentSum] = dp[i-1][currentSum-arr[i]];
            }
        }
    }
    return dp[n-1][sum];
}
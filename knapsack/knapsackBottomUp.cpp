#include<iostream>
#include<vector>
using namespace std;

class KnapsackBottomUp 
{
    public:
        int compute(const vector<int> &profits, const vector<int> &weights, int capacity)
        {
            // Error Handling
            if (capacity <= 0) {
                return 0;
            }

            // Create NxC Grid with values initialized to -1 profit
            vector<vector<int>> dp(profits.size(), vector<int>(capacity+1, -1));

            // Start building the grid bottom up from Capacity = 0 to 7 for each item being included or excluded
            int n = profits.size();
            
            for (int i = 0; i < n; i++) {
                dp[i][0] = 0;
            }

            for (int c = 0; c <=capacity; c++) {
                if (weights[0] <= c) {
                    dp[0][c] = profits[0];
                }
            }

            for (int i = 1; i < n; i++) {
                for (int c = 1; c <=capacity; c++) {
                    int profit1 = 0, profit2 = 0;

                    // Include it case: Profit1
                    if (weights[i] <= c) {
                        profit1 = profits[i] + dp[i-1][c-weights[i]];
                    }

                    // Skip it case: Profit2
                    profit2 = dp[i-1][c];

                    // Choose max profit choice
                    dp[i][c] = max(profit1,profit2);
                }
            }

            return dp[n-1][capacity];
        }
};


int main(int argc, char **argv)
{
    KnapsackBottomUp ks;

    vector<int> profits = {1,6,10,16};
    vector<int> weights = {1,2,3,5};

    int maxProfit = ks.compute(profits, weights, 7);

    cout << "Total Profit: " << maxProfit << endl;
    return 0;
}
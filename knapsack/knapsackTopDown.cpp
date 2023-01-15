using namespace std;

#include<iostream>
#include<vector>

class Knapsack
{
    public:
        int compute(const vector<int> &profits, const vector<int> &weights, int capacity)
        {
            // NxC Grid array
            vector<vector<int>> dp(profits.size(), vector<int>(capacity+1,-1));

            return this->knapsackRecursive(dp, profits, weights, capacity, 0);
        }

    private:
        int knapsackRecursive(vector<vector<int>> &dp, const vector<int> &profits, const vector<int> &weights, int capacity, int currentIndex)
        {
            // Base condition: Zero profit
            if (capacity <= 0 || currentIndex >= profits.size()) {
                return 0;
            }

            // Is subproblem already solved. If yes, reuse
            if (dp[currentIndex][capacity] != -1) {
                return dp[currentIndex][capacity];
            }

            // Either include current element or skip it to compute 2 profits
            // Case 1 Profit Calculation: Include current fruit/element
            int profit1 = 0;
            if (weights[currentIndex] <= capacity) {
                profit1 = profits[currentIndex] + knapsackRecursive(dp, profits, weights, capacity-weights[currentIndex], currentIndex + 1);
            }

            // Case 2 Profit calculation: Exclude current fruit
            int profit2 = knapsackRecursive(dp,profits, weights,capacity, currentIndex+1);

            // Choose max profit choice amongst the two choices
            dp[currentIndex][capacity] = max(profit1, profit2);

            // Return best profit up until that capacity and seeing the current fruit
            return dp[currentIndex][capacity];
        }
};

int main(int argc, char **argv)
{
    Knapsack ks;

    vector<int> profits = {1,6,10,16};
    vector<int> weights = {1,2,3,5};

    int maxProfit = ks.compute(profits, weights, 7);

    cout << "Total Profit: " << maxProfit << endl;

    return 0;
}
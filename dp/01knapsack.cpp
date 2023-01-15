#include<iostream>
#include<vector>

class KnapSack01
{
    public:
        int compute(vector<int> &weights, vector<int> &values, int capacity)
        {
            vector<int> profits(capacity+1,0);

            for (int i = 0; i < values.size(); i++) {
                for (int c = capacity; c >= 0; c--) {
                    if (weights[i] <= c) {
                        profits[c] = max(profits[c], values[i] + profits[c-weights[i]]);
                    }
                }
            }

            return profits[capacity];
};

int main(int argc ,char **argv)
{
    KnapSack01 ksObj;
    vector<int> weights = {1,2,3,5};
    vector<int> values = 

}
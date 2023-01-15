#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class TwoCityScheduling
{
    public:
        int compute(vector<pair<int,int>> &costs)
        {
            vector<pair<int,int>> difference;

            for (int i = 0; i < costs.size(); i++) {
                difference.push_back({costs[i].first - costs[i].second, i});
            }

            sort(difference.begin(), difference.end());

            int minCost = 0;
            int idx = 0;
            int n = difference.size()/2;

            for (int i = 0;i < difference.size(); i++) {
                idx = difference[i].second;

                minCost += (i < n) ? costs[idx].first : costs[idx].second;    
            }
            return minCost;
        }
};



int main()
{
    std::vector<pair<int,int>> costs = {std::make_pair(10, 20), std::make_pair(30, 200), std::make_pair(400, 50), std::make_pair(30, 20)};
    TwoCityScheduling obj;
    cout << obj.compute(costs);
    return 0;

}
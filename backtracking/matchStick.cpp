#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MatchSticks
{
    private:
        bool backtrack(int stickIndex, vector<int> &solution, vector<int> &matchSticks, int requiredLength)
        {
            if (stickIndex == matchSticks.size() && solution.size() == matchSticks.size()) {
                return true;
            }

            if (matchSticks[stickIndex] > requiredLength) {
                return false;
            }
            bool result = false;;

            if (matchSticks[stickIndex] == requiredLength) {
                solution.push_back(matchSticks[stickIndex]);
                result = backtrack(stickIndex+1,solution,matchSticks,requiredLength);
            }
            else {
                if (matchSticks[stickIndex] < requiredLength) {
                    solution.push_back(matchSticks[stickIndex]);
                    result = backtrack(stickIndex+1,solution,matchSticks,requiredLength-matchSticks[stickIndex]);
                }
            }
            return result;
        }
    public:
        bool compute(vector<int> &matchSticks)
        {
            int n = matchSticks.size();

            if (n < 4)
                return false;
            
            int sum = 0;
            for (auto num:matchSticks) {
                sum += num;
            }

            if (sum < 4) {
                return false;
            }

            sort(matchSticks.begin(), matchSticks.end(), greater<>());

            int requiredLength = sum/4;

            vector<int> solution;

            bool out = backtrack(0, solution, matchSticks, requiredLength);

            return out;
        }
};

int main(int argc, char **argv)
{
    vector<int> matchSticks = {3,3,3,3,4};
    MatchSticks msObj;
    cout << msObj.compute(matchSticks);
}
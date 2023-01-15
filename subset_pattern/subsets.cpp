#include<iostream>
#include<vector>

using namespace std;

class DistinctSubsets {
    public:
        static vector<vector<int>> compute(const vector<int> &inputSet)
        {
            vector<vector<int>> outputSets = {{}};
            
            for (auto currentNumber:inputSet) {
                // For each subset in outputSets
                int n = outputSets.size();

                for (int j = 0; j < n; j++) {
                    vector<int> newSubset = outputSets[j];
                    newSubset.push_back(currentNumber);
                    outputSets.push_back(newSubset);
                }
            }

            return outputSets;
        } 


};

int main()
{
    vector<int> inputSet = {1,2,3};
    vector<vector<int>> out = DistinctSubsets::compute(inputSet);

    for (auto it1:out) {
        for (auto it2:it1) {
            cout << it2 << ",";
        }
        cout << endl;
    }

    return 0;
}
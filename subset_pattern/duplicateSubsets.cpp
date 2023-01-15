#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

class DistinctSubsetsWithDuplicates
{
    public:
        static vector<vector<int>> compute(vector<int> inputSet)
        {
            // Sort input Set -> Note input is not of const reference
            sort(inputSet.begin(), inputSet.end());
            
            vector<vector<int>> outputSets = {{}};
            int previousNumber = INT16_MAX;
            int start = 0, end = 0;
            int currentNumber;

            for (int i = 0; i < inputSet.size(); i++) {
                currentNumber = inputSet[i];
                
                int n = outputSets.size();
                
                
                // Duplicate
                if (currentNumber == previousNumber) {
                    for (int j = start; j < end; j++) {
                        vector<int> newSubset(outputSets[j]);
                        newSubset.push_back(currentNumber);
                        outputSets.push_back(newSubset); 
                    }
                }
                else {
                    for (int j = 0; j < n; j++) {
                        vector<int> newSubset(outputSets[j]);
                        newSubset.push_back(currentNumber);
                        outputSets.push_back(newSubset); 
                    }
                    start = n;
                    end = outputSets.size();
                }
                previousNumber = currentNumber;
            }
            return outputSets;
        }

};

int main()
{
    vector<int> inputSet = {1,3,5};
    vector<vector<int>> out = DistinctSubsetsWithDuplicates::compute(inputSet);

    for (auto it1:out) {
        for (auto it2:it1) {
            cout << it2 << ",";
        }
        cout << endl;
    }

    return 0;
}
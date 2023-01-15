using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>

vector<vector<int>> searchTriplets(const vector<int> &inputArr)
{
    vector<vector<int>> triplets = {};
    
    // for (int k = 0; k < inputArr[k] <= 0; k++) {
    int k = 0;
    while(inputArr[k] <= 0 && k < inputArr.size() - 2) {
        int fixedVal = inputArr[k];
        std::cout<<"Fixed Value is: " << fixedVal <<"\n";

        // Initialize leftPtr, rightPtr
        int i = k+1;
        int j = inputArr.size() - 1;

        while(i < j) {
            int currentSum = inputArr[i] + inputArr[j] + fixedVal;

            if (currentSum == 0) {
                triplets.push_back({fixedVal,inputArr[i], inputArr[j]});
                i++;
                j--;
            }
            else if (currentSum < 0) {
                i++;
            }
            else {
                j--;
            }
        }
        k++;
    }

    return triplets;
}

int main() 
{
    vector<int> inputArr = {-3, 0, 1, 2, -1, 1, -2};
    sort(inputArr.begin(), inputArr.end());
    vector<vector<int>> output = searchTriplets(inputArr);
    
    for (int i =0; i < output.size(); i++) {
        for (int j =0; j < output[i].size(); j++) 
            std::cout<<output[i][j];
        cout<<"\n";
    }

    return 0;
}
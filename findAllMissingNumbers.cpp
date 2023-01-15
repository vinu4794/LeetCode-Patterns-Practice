#include<iostream>
#include<vector>
using namespace std;

bool isInCorrectPlace(int val, int index) 
{
    if (index == val) {
        return true;
    }
    else {
        return false;
    }
}

vector<int> findAllMissingNumber(const vector<int> &inputVector)
{
    vector<int> newVector(inputVector.size(), -1);

    for (int start = 0; start < inputVector.size(); start++) {
        int correctIdx = inputVector[start] - 1;
        newVector[correctIdx] = inputVector[start];
    }

    vector<int> missingNumbers = {};
    for (int i = 0; i < newVector.size(); i++) {
        if (newVector[i] == -1) {
            cout << i+1 << " ";
            missingNumbers.push_back(i); 
        }
    }
    return missingNumbers;
}


int main()
{
    vector<int> inputArr = {2, 3, 1, 8, 2, 3, 5, 1};

    findAllMissingNumber(inputArr);

    return 0;

}
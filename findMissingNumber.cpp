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

int findMissingNumber(const vector<int> &inputVector)
{
    vector<int> newVector(inputVector.size() + 1, -1);

    for (int start = 0; start < inputVector.size(); start++) {
        int correctIdx = inputVector[start];
        newVector[correctIdx] = inputVector[start];
    }

    for (int i = 0; i < newVector.size(); i++) {
        //cout << newVector[i] << " ";
        
        if (newVector[i] == -1) {
            return i; 
        }
    }
    return -1;
}


int main()
{
    vector<int> inputArr = {3, 1, 5, 4, 2};

    int missingNum = findMissingNumber(inputArr);
    cout << "Missing number is: " << missingNum;

    return 0;

}
#include<iostream>
#include<vector>
using namespace std;

bool isInCorrectPlace(int val, int index) 
{
    if (index == val-1) {
        return true;
    }
    else {
        return false;
    }
}

vector<int>& cyclicSort(vector<int> &inputVector)
{
    for (int start = 0; start < inputVector.size(); start++) {
        while(!isInCorrectPlace(inputVector[start], start)) {
            // swap with correct place
            int temp = inputVector[start];
            int correctIdx = inputVector[start] - 1;
            inputVector[start] = inputVector[correctIdx];
            inputVector[correctIdx] = temp;
        }
        start++;
    }
    return inputVector;
}



int main()
{
    vector<int> inputArr = {3, 1, 5, 4, 2};

    for (auto iterator:cyclicSort(inputArr)) {
        cout << iterator << " ";
    }

}
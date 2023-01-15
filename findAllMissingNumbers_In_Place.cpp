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
            
            if (inputVector[correctIdx] == inputVector[start]) {  
                break;
            }
        }
        // start++;
    }

    for (int idx = 0; idx < inputVector.size(); idx++) {
        if (idx != inputVector[idx] - 1) {
            cout << idx + 1;
        }
    }

    return inputVector;
}



int main()
{
    vector<int> inputArr = {2, 4, 1, 2};

    for (auto iterator:cyclicSort(inputArr)) {
        //cout << iterator << " ";
    }

}
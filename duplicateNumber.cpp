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

vector<int> getDuplicateNumber(vector<int> &inputVector)
{
    vector<int> duplicateNumbers;
    for (int start = 0; start < inputVector.size(); start++) {
        
        while(!isInCorrectPlace(inputVector[start], start)) {
            
            // swap with correct place
            int temp = inputVector[start];
            int correctIdx = inputVector[start] - 1;
            inputVector[start] = inputVector[correctIdx];
            inputVector[correctIdx] = temp;
            
            if (inputVector[correctIdx] == inputVector[start]) {  
                duplicateNumbers.push_back(inputVector[start]);
                break;
            }
        }
        
    }
    return duplicateNumbers;
}



int main()
{
    vector<int> inputArr = {3, 4, 4, 5, 5};
    vector<int> out = getDuplicateNumber(inputArr);
    for (int idx = 0; idx < out.size(); idx++) {
        cout << out[idx] << " ";
    }

    return 0;    

}
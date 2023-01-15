using namespace std;

#include <iostream>
#include <string>
#include <set>
#include <vector>

vector<int> squareArray(const vector<int>& arr) 
{
    vector<int> output(arr.size(), 0);
    
    int i = 0;
    int j = arr.size() - 1;
    int k = arr.size() - 1;

    while (i<j) {
        int leftVal = arr[i] * arr[i];
        int rightVal = arr[j] * arr[j];

        if (leftVal > rightVal) {
            output[k--] = leftVal;
            i++;    
        }
        else {
            output[k--] = rightVal;
            j--;
        }
    }
    return output;

}

int main()
{
    vector<int> inputArr = {-2, -1, 0, 2, 3};
    vector<int> output = squareArray(inputArr);
    
    for (int i =0; i < inputArr.size(); i++) {
        std::cout<<output[i];
    }

    return 1;


}
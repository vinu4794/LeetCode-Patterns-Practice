#include<iostream>
#include<vector>

using namespace std;

class NumberRange {

    public:
        pair<int,int> find(vector<int> arr, int key)
        {
            pair<int,int> result(-1,-1);
            result.first = this->search(arr, key, false);
            result.second = this->search(arr, key, true);

            return result;

        }

    private:
        int search(vector<int> arr, int key, bool findMaxIndex)
        {
            int start = 0;
            int end = arr.size() - 1;

            int keyIndex = -1;

            while(start <= end) {
                int middle = start + (end-start)/2;

                if (key == arr[middle]) {
                    keyIndex = middle;

                    if (findMaxIndex) {
                        start = middle + 1;
                    }
                    else {
                        end = middle - 1;
                    }
                }
                else {

                    if (key < arr[middle]) {
                        end = middle - 1;
                    }
                    else {
                        start = middle + 1;
                    }
                }
            }

            return keyIndex;
        }

};

int main()
{
    NumberRange numRangeObj;
    pair<int,int> out = numRangeObj.find({4, 6, 6, 6, 9}, 6);
    cout << out.first << " ";
    cout << out.second << endl;
    return 0;
}
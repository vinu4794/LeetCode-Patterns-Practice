#include<iostream>
#include<vector>

using namespace std;

class CeilingNumber {
    public:
        static int find(const vector<int> &arr, int key)
        {
            int start = 0;
            int end = arr.size() - 1;

            if (key > arr[end]) {
                return -1;
            }

            while(start <= end) {
                int middle = start + (end-start)/2;

                if (key == arr[middle]) {
                    return middle;
                }

                if (key < arr[middle]) {
                    end = middle - 1;
                }
                else {
                    start = middle + 1;
                }
            }
            return start;
        }

};

int main()
{
    int out = CeilingNumber::find({4,6,10}, -1);
    cout << out << endl;
    return 0;
}
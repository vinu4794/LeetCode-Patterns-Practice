#include<iostream>
#include<vector>

using namespace std;

class NextLetter {
    public:
        static char find(const vector<char> &arr, char key)
        {
            int start = 0;
            int end = arr.size() - 1;

            if (key >= arr[end]) {
                return arr[0];
            }

            while(start <= end) {
                int middle = start + (end-start)/2;

                if (key == arr[middle]) {
                    return arr[middle+1];
                }

                if (key < arr[middle]) {
                    end = middle - 1;
                }
                else {
                    start = middle + 1;
                }
            }
            return arr[start];
        }

};

int main()
{
    char out = NextLetter::find({'f', 'g', 'h', 'i'}, 'f');
    cout << out << endl;
    return 0;
}
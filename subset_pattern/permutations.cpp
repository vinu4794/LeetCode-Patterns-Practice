#include<iostream>
#include<vector>
using namespace std;

class Permutations{
    public:
        static vector<vector<int>> compute(vector<int> inputSet)
        {
            vector<vector<int>> output;

            return output;
        }

};

int main()
{
    vector<vector<int>> output = Permutations::compute({1,3,5});
    cout << "Permutations are: " << endl;

    for (auto vec: output) {
        for (auto num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
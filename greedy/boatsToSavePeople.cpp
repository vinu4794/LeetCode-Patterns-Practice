#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class BoatsToSavePeople
{
    public:
        int compute(vector<int> people, int limit)
        {
            int numOfBoats = 0;

            sort(people.begin(), people.end());

            int left = people[0];
            int n = people.size();
            int right = people[n-1];

            while (n > 0) {
                int combinedWeight = left + right;

                if (combinedWeight <= limit) {
                    numOfBoats++;
                    left++;
                    right--;
                    n = n - 2;
                }
                else {
                    right--;
                    n--;
                    numOfBoats++;
                }
            }

            return numOfBoats;
        }
};

int main(int argc, char **argv)
{
    BoatsToSavePeople boatObj;

    vector<int> people = {1, 2, 3, 4, 5};
    cout << boatObj.compute(people, 3);
}
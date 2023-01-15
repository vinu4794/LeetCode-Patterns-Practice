#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class FrequentTopKElements
{
    struct greaterThanPair {
        bool operator()(const pair<int,int> &x, const pair<int,int> &y)
        {
            return x.second > y.second;
        }
    };

    public:
        static vector<int> compute(const vector<int> &arr, int k)
        {
            vector<int> result;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greaterThanPair> minHeap; 

            unordered_map<int,int> freqMap;
            for (auto num:arr) {
                freqMap[num]++;
            } 

            for (auto currentPair:freqMap) {
                minHeap.push(currentPair);

                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }

            while(!minHeap.empty()) {
                int ele = minHeap.top().first;
                minHeap.pop();
                result.push_back(ele);
            }



            return result;
        }
};

int main(int arg, char **argv)
{
    vector<int> out = FrequentTopKElements::compute({1, 3, 5, 12, 11, 12, 11},2);

    for (auto num:out) {
        cout << num << " ";
    }
    return 0;
}
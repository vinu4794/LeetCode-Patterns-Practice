#include<iostream>
#include<vector>
using namespace std;

class JumpGame1 
{
    private:
        bool isReachable(const vector<int> &nums, int precedingIdx, int currentTarget)
        {
            if (precedingIdx == currentTarget) {
                return true;
            }
            for (int stepValue = 1; stepValue <= nums[precedingIdx]; stepValue++) {
                if (precedingIdx+stepValue == currentTarget) {
                    return true;
                }
            }
            return false;
        }
    public:
        bool compute(const vector<int> &nums)
        {
            int currentTarget = nums.size() - 1;

            int precedingIdx = currentTarget - 1;

            while(precedingIdx != 0) {
                if (this->isReachable(nums, precedingIdx, currentTarget)) {
                    currentTarget--;
                }
                precedingIdx--;
            }

            if (currentTarget == 1) {
                return true;
            }
            return false;
        }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    JumpGame1 jgObj;
    bool res = jgObj.compute(nums);
    cout << res;

    return 0;
}
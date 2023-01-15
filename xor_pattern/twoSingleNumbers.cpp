#include<iostream>
#include<vector>
using namespace std;

class TwoMissingNumbers {
    public:
        static vector<int> compute(const vector<int> &arr) 
        {
            int n1xn2 = 0;
            
            // XOR all numbers amongst themselves
            // Final result is the xor of the two missing numbers
            for (int num : arr) {
                n1xn2 ^= num;
            }

            // Get the rightmost bit which is set to 1
            // This is needed because the bit differing in both numbers
            // would have resulted in the set bit in n1xn2
            // We then want to make two groups:
            // Group 1: Numbers with that particular single bit set
            // Group 2: Numbers with that particular single bit not set
            int rightMostSetBit = 1;

            while (rightMostSetBit & n1xn2 == 0) {
                rightMostSetBit = rightMostSetBit << 1;
            }

            int num1 = 0, num2 = 0;

            for (int num:arr) {
                if ((num & rightMostSetBit) != 0) {
                    num1 ^= num;
                }
                else {
                    num2 ^= num;
                }
            }

            return vector<int>{num1,num2};
        }
};
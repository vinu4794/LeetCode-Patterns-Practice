#include<iostream>
#include<unordered_map>

using namespace std;

class LongestSubstringKDistinct {
    public:
        static int findLength(const string &str, int k) {
            int windowStart = 0;
            int maxLength = 0;
            unordered_map<char,int> charFreqMap;
            
            for (int windowEnd = 0; windowEnd < str.size(); windowEnd++) {
                char ch = str[windowEnd];
                charFreqMap[ch]++;

                // Keep Shrinking the window at each step until you are left with
                // K distinct chars; when you shrink the window, windowEnd remains const
                // and only windowStart increases. Thus it is done at each step.
                while(charFreqMap.size() > k) {
                    char leftChar = str[windowStart];
                    charFreqMap[leftChar]--;

                    if (charFreqMap[leftChar] == 0) {
                        charFreqMap.erase(leftChar);
                    }
                    windowStart++;
                }

                maxLength = max(maxLength, windowEnd-windowStart+1);
            }

            return maxLength;

        }

};

int main()
{
    string str = "araaci";
    int k = 2;

    int out = LongestSubstringKDistinct::findLength(str, k);
    cout << out;

    return 0;
}
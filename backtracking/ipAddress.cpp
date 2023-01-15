#include<iostream>
#include<string>
#include<vector>

using namespace std;

class IPAddresses {
    bool valid(string segment) {
        int m = segment.length();
        if (m > 3)
            return false;
        return segment[0] != '0' ? stoi(segment) <= 255 : m == 1;
    }

    void updateSegment(string s, int currPos, vector<string>& segments,
                            vector<string>& result) {
        
        string segment = s.substr(currPos + 1, s.size() - currPos - 1);
        if (valid(segment)) {
            segments.push_back(segment);
            // Utility function to concate the entries of the segments list
            // separated by the dot delimeter.
            string ip = join(".", segments); 
            result.push_back(ip);
            segments.pop_back();
        }
    }

    void backtrack(string s, int prevPos, int dots, vector<string>& segments,
                        vector<string>& result) {
        
        int size = s.length();
        int maxPos = min(size - 1, prevPos + 4);
        
        for (int currPos = prevPos + 1; currPos < maxPos; currPos++) {
            string segment = s.substr(prevPos + 1, currPos - prevPos);
            if (valid(segment)) {
                segments.push_back(segment);  // place dot
                if (dots - 1 == 0)      // if all 3 dots are placed
                    updateSegment(s, currPos, segments, result);  // add the solution to output
                else
                    backtrack(s, currPos, dots - 1, segments, result);  // continue to place dots
                    segments.pop_back();  // remove the last placed dot
            }
        }
    }
    public:
        vector<string> compute(string inputStr)
        {
            vector<string> result;
            vector<string> segments;
            backtrack(inputStr, -1, 3, segments, result);           
        }
};


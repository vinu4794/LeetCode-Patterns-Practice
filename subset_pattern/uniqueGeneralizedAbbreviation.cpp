#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class UniqueGeneralizedAbbreviation {
    public:
        static vector<string> compute(const string &inputWord)
        {
            vector<string> result;

            queue<string> q1;

            q1.push("");

            int n = 0;
            
            for (int i = 0; i < inputWord.size(); i++) {
                int n = q1.size();

                for (int j = 0; j < n; j++) {
                    string abWord = q1.front(); 
                    q1.pop();

                    // Abbrevate
                    string newAbWord = abWord + "-";
                    q1.push(newAbWord);

                    // Skip
                    newAbWord = abWord + inputWord[i];
                    q1.push(newAbWord);
                }
            }

            string str;
            while (!q1.empty()) {
                str = q1.front();
                q1.pop();

                // str = replaceDashWithNums(str);

                result.push_back(str);
            }
            return result;
        }
    // private:
    //     string replaceDashWithNums(const string &str)
    //     {
    //         string outStr;
            
    //     }

};

int main()
{
    vector<string> result = UniqueGeneralizedAbbreviation::compute("BAT");

    for (auto str:result) {
        cout << str << endl;
    }

    return 0;
}
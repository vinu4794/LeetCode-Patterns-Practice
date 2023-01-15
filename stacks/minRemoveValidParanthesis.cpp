#include<string>
#include<vector>
#include<iostream>
using namespace std;
#include<stack>

string MinRemoveParentheses(string s) {
    
    stack<pair<char,int>> parenStack;

    for (int i = 0; i < s.length(); i++) {
        char currentChar = s[i];

        if (currentChar == '(') {
            parenStack.push(pair<char,int>(currentChar,i));
        }

        else if (currentChar == ')') {
            if (parenStack.empty()) {
                parenStack.push(pair<char,int>(currentChar,i));
            }
            else {
                if (parenStack.top().first == '(') {
                    parenStack.pop();
                }
                else if (parenStack.top().first == ')') {
                    parenStack.push(pair<char,int>(currentChar,i));
                }
            }
        }
    }

    if (!parenStack.empty()) {
        string result;

        int idxToFind = parenStack.top().second;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (i == idxToFind) {
                parenStack.pop();
                if (!parenStack.empty()) {
                    idxToFind = parenStack.top().second;
                }
                else {
                    idxToFind = -1;
                }
            }
            else {
                result.insert(result.begin(), 1, s[i]);
            }
        }
        return result;
    }
    else {
        return s;
    }
}

int main() {
  std::vector < std::string > inputs = {
    "ar)ab(abc)abd(",
    "a)rt)lm(ikgh)"
  };

  for (int i = 0; i < inputs.size(); i++) {
    std::cout << i + 1 << ".\tInput: \"" << inputs[i] << "\"" << std::endl;
    std::cout << " \tAfter removal: \"" <<
      MinRemoveParentheses(inputs[i]) << "\"" << std::endl;
    std::cout << std::string(100, '-') << std::endl;
  }
}
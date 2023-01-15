// Template for TrieNode class
#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

class TrieNode {
   public:
       std::map<char, TrieNode*> children;
       bool isWord;
 
       TrieNode(){
           this->isWord = false;
       }
};
class Trie {
    public:
        TrieNode *head;
        Trie(){
            this->head = new TrieNode();
            
        }

        // inserting string in trie
        // bat, bye
        void insert(string word) { // bye
            TrieNode *currentNode = head; // at root
            for (int i = 0; i < word.length(); i++) {
                char currentChar = word[i]; 
                
                // Not found
                if (currentNode->children.find(currentChar) == currentNode->children.end()) {
                    currentNode->children[currentChar] = new TrieNode();
                }
                currentNode = currentNode->children[currentChar];
            }    
            currentNode->isWord = true;        
        }
};

void dfsUtil(TrieNode *root, string &string1, vector<string> &subresult)
{
    if (!root) {
        string result = string1;
        string1.pop_back();
        subresult.push_back(result);
        return;
    }
    TrieNode *currentNode = root;
    
    for(auto rootChildIter = currentNode->children.begin(); rootChildIter != currentNode->children.end(); ++rootChildIter) {
        
        // At 'b'
        char currentChar =  rootChildIter->first;
        //TrieNode* value = rootChildIter->second;
        string1.push_back(currentChar);

        dfsUtil(rootChildIter->second,string1,subresult);
    }
    string1.pop_back();
}


vector<vector<string>> SuggestedProducts(vector<string> products, string searchWord){

    vector<vector<string>> result;
    // Initialize Trie DS
    Trie *trieDS = new Trie();

    // Insert Products/words into the trie
    for (auto product:products) {
        trieDS->insert(product);
    }

    // Print possible suggestions as and when a letter is read
    
    TrieNode *currentNode = trieDS->head; // at root
    for (int i = 0; i < searchWord.length(); i++) {
        string string1;
        char currentChar = searchWord[i]; 

        // Not found
        if (currentNode->children.find(currentChar) == currentNode->children.end()) {
            break;    
        }

        vector<string> subresult;
        dfsUtil(currentNode,string1,subresult);
        result.push_back(subresult);

        // Go to next node
        currentNode = currentNode->children[currentChar];
    }    
    return result;
}


// Driver code
int main() {
  std::vector < std::string > products = {
    "bat",
    "bag",
    "bassinet",
    "bread",
    "cable",
    "table",
    "tree",
    "tarp"
  };
  std::vector < std::string > searchWordList = {
    "ba"
    // ,"in",
    // "ca",
    // "t"
  };
  for (int i = 0; i < searchWordList.size(); i++) {
    std::vector < std::vector < std::string >> result = SuggestedProducts(products, searchWordList[i]);
    std::cout << "\tSuggested  Products: ";
    for (auto sublist:result) {
        for (int i = 0; i < sublist.size(); i++) {
            cout << sublist[i] << ", ";
        }
        cout << endl;
    }
    std::cout << std::string(100, '-') << "\n";
  }
  return 0;
}

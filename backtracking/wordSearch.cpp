#include<iostream>
#include<vector>
#include<string>
using namespace std;

class WordSearch
{
    private:
        bool DFS(int row, int col, string word, vector<vector<char>> &grid) 
        {
            if (word.length() == 0) {
                return true;
            }

            // Check if this is a valid cell
            if (row < 0 || row == grid.size() || col < 0 || col == grid[0].size() || std::tolower(grid[row][col]) != std::tolower(word[0])) {
                return false;
            }
            
            bool result = false;

            vector<std::vector<int>> offsets{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            
            for (auto offset : offsets) {
                int rowOffset = offset[0];
                int colOffset = offset[1];
                result = DFS(row + rowOffset, col + colOffset, word.substr(1), grid);
                
                if (result) {
                    break;
                }
            }
            return result;
        }
    public:
        bool compute(std::vector<std::vector<char>> grid, std::string word)
        {
            // Why call DFS for each cell in the grid?
            // Because: The word path could start from any cell in the grid
            for (int row = 0; row < grid.size(); row++) { // Start char may not be in the first row
                for (int col = 0; col < grid[0].size(); col++) {
                    if (DFS(row,col,word,grid)) {
                        return true;
                    }
                }
            }
            return false;
        }
};

int main(int argc, char **argv)
{
    WordSearch wsObj;
    vector<vector<char>> grid = {{'E', 'D', 'X', 'I', 'W'},
         {'P', 'U', 'F', 'M', 'Q'},
         {'I', 'C', 'Q', 'R', 'F'},
         {'M', 'A', 'L', 'C', 'A'},
         {'J', 'T', 'I', 'V', 'E'}};
    string inputStr("EDUCATIVE");
    cout << wsObj.compute(grid,inputStr);
}
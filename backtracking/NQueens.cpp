#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NQueens
{
    private:
        int n;
        // vector<vector<int>> grid;
        bool isSafe(int proposedRow, int proposedCol, std::vector<int>& solution) {

            int old_row = 0, old_col = 0, diagonal_offset = 0;

            for (int i = 0; i < proposedRow; i++) {
                old_row = i;
                old_col = solution[i];
                diagonal_offset = proposedRow - old_row;

                if (old_col == proposedCol || old_col == proposedCol - diagonal_offset ||
                        old_col == proposedCol + diagonal_offset) {
                    return false;
                }
            }
            return true;
}

    public:
        int compute(int n)
        {
            vector<int> solution(n, -1);
            vector<vector<int>> results;

            nqueensUtil(n, 0, solution, results);

            return results.size();
        }

        void nqueensUtil(int n, int row, vector<int> &solution, vector<vector<int>> &results) 
        {
            if (row == n) {
                results.push_back(solution);
                return;
            }

            for (int col = 0; col < n; col++) {
                if (isSafe(row,col,solution)) {
                    solution[row] = col;
                    nqueensUtil(n,row+1,solution,results);
                }
            }
            
        } 
};

int main(int argc, char **argv)
{
    NQueens queenObj;
    cout << queenObj.compute(4);
}
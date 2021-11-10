// problem source: https://leetcode.com/problems/sudoku-solver/
// discussion reference: https://leetcode.com/problems/sudoku-solver/discuss/1566204/Easy-C++-Solution
class Solution {
public:
    bool isValidBoard(char element, int row, int column, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == element) // checking valid row
                return false; // exist element
            if (board[i][column] == element) // checking valid column
                return false; // exist element
            if (board[3 * (row / 3) + i / 3][3 * (column / 3) + i % 3] == element) // checking sub board
                return false; // exist element
        }
        return true; // not exist element in board
    }
    bool recursionMethod(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') { // blank space
                    for (char element = '1'; element <= '9'; element++) {
                        if (isValidBoard(element, i, j, board)) { // put location and board
                            board[i][j] = element; // fill the board
                            if (recursionMethod(board)) // and verification
                                return true;
                            else
                                board[i][j] = '.'; // if not satisfied
                        }
                    }
                    return false; // rollback board
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // for (int i = 0; i < 9; i++) {
        //     for (int j = 0; j < 9; j++)
        //         cout << board[i][j] << " ";
        //     cout << endl;
        // }
        recursionMethod(board);
    }
};

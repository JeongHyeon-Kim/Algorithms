// problem source: https://leetcode.com/problems/n-queens/
// discussion reference: https://leetcode.com/problems/n-queens/discuss/2107895/C++-Backtracking-Beginner-Friendly-Solution-w-Explanation
/*
퀸은 위치 기준 가로, 세로, 대각선으로 움직일 수 있음
가로 또는 세로 선과 대각선 사이의 공간에 위치할 때 서로 공격 불가
n을 기준으로 판 생성 및 퀸 갯수 지정 
*/

// Runtime: 11 ms, faster than 45.35% of C++ online submissions for N-Queens.
// Memory Usage: 7.4 MB, less than 47.93% of C++ online submissions for N-Queens.
class Solution {
    vector<vector<string>> result;
public:
    bool isSafe(int row, int column, vector<string>& solving, int n) {
        for (int i = 0; i < row; i++) {
            if (solving[i][column] == 'Q')
                return false;
        }
        int row_check = row;
        int column_check = column;
        while (row_check >= 0 && column_check >= 0) { //upper left
            if (solving[row_check][column_check] == 'Q')
                return false;
            row_check--;
            column_check--;
        }
        row_check = row;
        column_check = column;
        while (row_check >= 0 && column_check < n) { // upper right
            if (solving[row_check][column_check] == 'Q')
                return false;
            row_check--;
            column_check++;
        }
        return true;
    }
    void backtracking(int row, vector<string> &solving, int n) {
        if (row == n) {
            result.push_back(solving);
            return ;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(row, i, solving, n)) {
                solving[row][i] = 'Q';
                backtracking(row + 1, solving, n);
                solving[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> solving;
        string init(n, '.');
        for (int i = 0; i < n; i++)
            solving.push_back(init);
        backtracking(0, solving, n);
        return result;
    }
};
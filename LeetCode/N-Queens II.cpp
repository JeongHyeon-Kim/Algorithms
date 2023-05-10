// problem source: https://leetcode.com/problems/n-queens-ii/description/
// discussion reference: https://leetcode.com/problems/n-queens-ii/solutions/2111583/cpp-explained-clean
// 두 퀸이 서로를 공격하지 않도록 체스판에 퀸 배치, 배치 가능한 해결책의 갯수 반환
// 퀸은 룩과 비숍을 합쳐 놓은 것처럼 이동, 상하좌우 및 대각선
// backtracking 기법 활용
class Solution {
public:
    int solve(vector<bool> column, vector<bool> diagonal, vector<bool> anti_diagonal, int row) {
        // diagonal: 왼쪽 위 ~ 오른쪽 아래 대각선 
        // anti_diagonal: 오른쪽 위 ~ 왼쪽 아래 대각선
        // n의 갯수만큼 퀸을 배치, count는 솔루션 갯수
        int column_size = column.size();
        int count = 0;
        if (row == column_size) return 1;
        for (int col = 0; col < column_size; col++) {
            if (!column[col] && // 열
            !diagonal[row + col] && // 대각선
            !anti_diagonal[row - col + column_size - 1]) { // 반대각선
                column[col] = true;
                diagonal[row + col] = true;
                anti_diagonal[row - col + column_size - 1] = true;

                count += solve(column, diagonal, anti_diagonal, row + 1);

                column[col] = false;
                diagonal[row + col] = false;
                anti_diagonal[row - col + column_size - 1] = false;
            }
        }
        return count;
    }
    int totalNQueens(int n) {
        vector<bool> column(n), diagonal(2 * n - 1), anti_diagonal(2 * n - 1);
        return solve(column, diagonal, anti_diagonal, 0);
    }
};
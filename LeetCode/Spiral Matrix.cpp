// problem source: https://leetcode.com/problems/spiral-matrix/
// discussion reference: https://leetcode.com/problems/spiral-matrix/solutions/978853/c-0ms-faster-than-100-easy-solution-with-proper-explanation/

// 행과 열의 기점/종점을 기준으로 진행 방향 변경 (오른쪽, 아래, 왼쪽, 위로)
// 기점과 종점의 크기가 점점 줄어들기 때문에 체킹 필요

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0;
        int j = 0;
        int element_count = 0;
        int direction = 0;
        while (element_count < row * col) {
            result.push_back(matrix[i][j]);
            matrix[i][j] = 0;
            element_count++;
            if (direction == 0) {
                if (j == col - 1 || matrix[i][j + 1] == 0) {
                    direction = 1;
                    i++;
                } else {
                    j++;
                }
            } else if (direction == 1) {
                if (i == row - 1 || matrix[i + 1][j] == 0) {
                    direction = 2;
                    j--;
                } else {
                    i++;
                }
            } else if (direction == 2) {
                if (j == 0 || matrix[i][j - 1] == 0) {
                    direction = 3;
                    i--;
                } else {
                    j--;
                }
            } else if (direction == 3) {
                if (i == 0 || matrix[i - 1][j] == 0) {
                    direction = 0;
                    j++;
                } else {
                    i--;
                }
            }

        }
        return result;
    }
};
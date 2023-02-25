// problem source: https://leetcode.com/problems/rotate-image/submissions/
// discussion reference
// - https://velog.io/@danbibibi/2차원-배열에서-90도-회전-알고리즘
// - https://80000coding.oopy.io/875e96fc-6849-41c8-9f1a-6fc702b8a91c

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
// Memory Usage: 7.2 MB, less than 41.19% of C++ online submissions for Rotate Image.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matrix_size = matrix.size();
        vector<vector<int>> temp(matrix_size, vector<int>(matrix_size));
        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) { // n by n
                temp[j][matrix_size - 1 - i]  = matrix[i][j];
            }
        }
        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) { // n by n
                matrix[i][j] = temp[i][j];
            }
        }
        
    }
};
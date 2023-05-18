class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int numbering = 1;
        int row = 0;
        int column = 0;
        int direction = 0;
        vector<int> direction_row = {0, 1, 0, -1};
        vector<int> direction_column = {1, 0, -1, 0};

        while (numbering <= n * n) {
            result[row][column] = numbering; // insert number
            numbering++; // increase number
            // change direction
            int next_row = row + direction_row[direction];
            int next_column = column + direction_column[direction];
            if (next_row < 0 || next_row >= n || next_column < 0 || next_column >= n 
            || result[next_row][next_column] != 0) {
                direction = (direction + 1) % 4; // four direction
            }
            row += direction_row[direction];
            column += direction_column[direction];
        }
        return result;
    }
};
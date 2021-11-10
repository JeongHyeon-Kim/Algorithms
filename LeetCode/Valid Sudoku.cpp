class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int board_size = board.size();
        bool result = true;
        map<char, int> valid_row;
        map<char, int> valid_column;
        map<char, int> valid_sub;
        // for (int i = 0; i < 9; i++) {
        //     for (int j = 0; j < 9; j++) {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 0; i < 9; i++) {
            valid_row.clear();
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.')
                    valid_row[board[i][j]]++;
            }
            for (auto it = valid_row.begin(); it != valid_row.end(); it++) {
                if (it->second > 1)
                    result = false;
            }
        }
        for (int i = 0; i < 9; i++) {
            valid_column.clear();
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.')
                   valid_column[board[j][i]]++;
            }
            for (auto it = valid_column.begin(); it != valid_column.end(); it++) {
                if (it->second > 1)
                    result = false;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            // 0 3 6
            for (int j = 0; j < 9; j += 3) {
                // 0 3 6
                valid_sub.clear();
                for (int k = i; k < i + 3; k++) {
                    // 0 1 2
                    for (int l = j; l < j + 3; l++) {
                        // 0 1 2
                        // cout << board[k][l] << " ";
                        if (board[k][l] != '.')
                            valid_sub[board[k][l]]++;
                    }
                    // cout << endl;
                }
                // cout << endl;
                for (auto it = valid_sub.begin(); it != valid_sub.end(); it++) {
                    // cout << "count is "<< it->second << endl;
                    if (it->second > 1)
                        result = false;
                }
            }
        }
        return result;
    }
};

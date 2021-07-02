class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        vector<vector<char>> surround = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        queue<pair<int, int>> location;
        location.push({i, j});
        int row = grid.size();
        int col = grid[0].size();
        grid[i][j] = '0'; // '1' -> '0'
        while(!location.empty()) {
            int location_size = location.size();
            for (int i = 0; i < location_size; i++) {
                int x = location.front().first;
                int y = location.front().second;
                location.pop();
                for (int j = 0; j < 4; j++) {
                    int x1 = x + surround[j][0];
                    int y1 = y + surround[j][1];

                    if (x1 >= 0 && y1 >= 0 && x1 < row && y1 < col) {
                        if(grid[x1][y1] == '1') {
                            location.push({x1, y1});
                            grid[x1][y1] = '0'; // '1' -> '0'
                        }
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int island = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // cout << grid[i][j] << " ";
                if (grid[i][j] == '1') {
                    island++;
                    bfs(grid, i, j);
                }
            }
            // cout << endl;
        }
        return island;
    }
};

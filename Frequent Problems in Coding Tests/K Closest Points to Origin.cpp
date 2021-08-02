// problem source: https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int x_max = points.size();
        int y_max = points[0].size();
        vector<vector<int>> result;
        for (int x = 0; x < x_max; x++) {
            for (int y = 0; y < y_max; y++) {
                cout << points[x][y] << " ";
            }
            cout << endl;
        }
        cout << k << endl;
        return result;
    }
};

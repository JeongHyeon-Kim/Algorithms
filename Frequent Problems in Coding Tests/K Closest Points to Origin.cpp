// problem source: https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int x_max = points.size();
        multimap<int, vector<int>> middle; // distance, location (accept redundancy)
        vector<vector<int>> result;
        for (int x = 0; x < x_max; x++) {
            int square = 0;
            vector<int> location;
            for (int y = 0; y < 2; y++) {
                location.push_back(points[x][y]);
                square += points[x][y] * points[x][y];
            }
            int fake_distance = square;
            middle.insert(pair<int, vector<int>>(fake_distance, location));
        }
        auto it = middle.begin();
        for (int i = 0; i < k && it != middle.end(); i++, it++) {
            vector<int> temp = it->second;
            result.push_back(temp);
        }
        return result;

        // Runtime Error with [[0,1],[1,0]], 2
        // int x_max = points.size();
        // unordered_map<int, vector<int>> middle; // distance, location
        // vector<vector<int>> result;
        // for (int x = 0; x < x_max; x++) {
        //     int square = 0;
        //     vector<int> location;
        //     for (int y = 0; y < 2; y++) {
        //         location.push_back(points[x][y]);
        //         square += points[x][y] * points[x][y];
        //     }
        //     int fake_distance = square;
        //     middle[fake_distance] = location;
        // }
        // std::map<int, vector<int>> ordered(middle.begin(), middle.end());
        // auto it = ordered.begin();
        // for (int i = 0; i < k; i++) {
        //     vector<int> temp = it->second;
        //     result.push_back(temp);
        //     it++;
        // }
        // return result;
    }
};

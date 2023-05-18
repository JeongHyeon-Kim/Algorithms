class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        cout << n << endl;
        int total_count = n * n;
        if (total_count == 1) {
            vector<int> middle_result;
            middle_result.push_back(total_count);
            result.push_back(middle_result);
        }
        return result;
    }
};
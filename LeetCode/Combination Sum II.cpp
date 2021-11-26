// problem source: https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int candidates_size = candidates.size();
        vector<vector<int>> result;
        for (int i = 0; i < candidates_size; i++)
            cout << candidates[i] << " ";
        cout << endl;
        cout << target << endl;
        return result;
    }
};

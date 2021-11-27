// problem source: https://leetcode.com/problems/combination-sum-ii/
// discussion reference: https://leetcode.com/problems/combination-sum-ii/discuss/16861/Java-solution-using-dfs-easy-understand
class Solution {
public:
    // java to c++
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result; // List<List<Integer>> result = new ArrayList<List<Integer>>();
        vector<int> path; // List<Integer> path = new ArrayList<Integer>();
        dfs_solution(candidates, 0, target, path, result);
        return result;
    }

    void dfs_solution(vector<int> candidates, int current_index, int target, vector<int> path, vector<vector<int>>& result) { // int[] canditates, int current_index, List<Integer> path, List<List<Integer>> result
        if (target == 0) {
            result.push_back(path); // found, making result // result.add(new ArrayList(path));
            return;
        }

        if (target < 0) return;

        for (int i = current_index; i < candidates.size(); i++) {
            if (i > current_index && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]); // path.add(path.size(), cand[i]);
            dfs_solution(candidates, i + 1, target - candidates[i], path, result);
            path.pop_back(); // path.remove(path.size() - 1);
        }

    }
};

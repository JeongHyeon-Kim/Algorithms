// problem source: https://leetcode.com/problems/combination-sum/
// discussion reference: https://leetcode.com/problems/combination-sum/discuss/1583376/Backtracking-Template
class Solution {
public:
    void recursive_method(vector<int>& candidates, int remain_sum, vector<vector<int>>& result, vector<int>& individual_result, int start_index) { // decrease from target
        int candidates_size = candidates.size();
        if (remain_sum == 0) // found
            result.push_back(individual_result);
        else {
            if (remain_sum > 0) {
                for (int i = start_index; i < candidates_size; i++) {
                    individual_result.push_back(candidates[i]);
                    recursive_method(candidates, remain_sum - candidates[i], result, individual_result, i); // decrease from target
                    individual_result.pop_back(); // not include candidates[i];
                }
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> individual_result;
        recursive_method(candidates, target, result, individual_result, 0);
        return result;
    }
    // Initial Code
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     vector<vector<int>> result;
    //     vector<int> temp;
    //     int candidates_size = candidates.size();
    //     int sub_sum = 0;
    //     for (int i = 0; i < candidates_size; i++) {
    //         while (sub_sum + candidates[i] <= target) {
    //             sub_sum += candidates[i];
    //             temp.push_back(candidates[i]);
    //             if (sub_sum == target) {
    //                 result.push_back(temp);
    //                 temp.clear();
    //                 sub_sum = 0;
    //                 break;
    //             }
    //         }
    //     }
    //     return result;
    // }
};

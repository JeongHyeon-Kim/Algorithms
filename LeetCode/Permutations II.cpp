// problem source: https://leetcode.com/problems/permutations-ii/
// discussion reference: https://mjmjmj98.tistory.com/38

// Runtime: 6 ms, faster than 83.86% of C++ online submissions for Permutations II.
// Memory Usage: 9.1 MB, less than 69.11% of C++ online submissions for Permutations II.

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int nums_size = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        do {
            vector<int> cases;
            for (auto it = nums.begin(); it != nums.end(); ++it)
                cases.push_back(*it);
            result.push_back(cases);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }
};
// problem source: https://leetcode.com/problems/permutations/
// dicussion reference: https://mjmjmj98.tistory.com/38
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        result.push_back(nums);
        while(next_permutation(nums.begin(), nums.end()))
            result.push_back(nums);
        return result;
    }
};

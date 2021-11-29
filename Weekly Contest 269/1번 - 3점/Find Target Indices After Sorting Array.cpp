// problem source: https://leetcode.com/contest/weekly-contest-269/problems/find-target-indices-after-sorting-array/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;
        int nums_size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums_size; i++) {
            if (nums[i] == target)
                result.push_back(i);
        }
        return result;
    }
};

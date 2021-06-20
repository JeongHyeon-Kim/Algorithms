// problem source: https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int nums_size = nums.size();
        vector<int> result;
        for (int i = 0; i < nums_size - 1; i++) {
            for (int j  = i + 1; j < nums_size; j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};

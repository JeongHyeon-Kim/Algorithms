// problem source: https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int nums_size = nums.size();
        sort(nums.begin(), nums.end());
        return nums[nums_size - k];
    }
};

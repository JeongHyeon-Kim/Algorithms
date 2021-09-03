// problem source: https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // get the target int nums array
        // ascending order, distinct
        unordered_map<int, int> data;
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++)
            data[nums[i]] = i;
        if (data.find(target) == data.end())
            return -1;
        else
            return data[target];
    }
};

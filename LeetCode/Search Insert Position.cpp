// problem source: https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // All PASS Presented Test Case
        int nums_size = nums.size();
        int result_position = 0;
        for (int i = 0; i < nums_size; i++) {
            if (target <= nums[i]) {// get or inserted
                result_position = i;
                break;
            } else if (i == nums_size - 1) // bigger than all elements
                result_position = nums_size;
        }
        return result_position;
    }
};

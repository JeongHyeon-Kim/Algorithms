// problem source: https://leetcode.com/problems/house-robber-ii/
// dicussion reference: https://leetcode.com/problems/house-robber-ii/discuss/1578257/C++-dp-solution-(beats-100)
class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> data(nums_size - 1); // for iteration index value
        vector<int> compare_data(nums_size - 1);
        // exception cases
        if (nums_size == 1)
            return nums[0];
        else if (nums_size == 2)
            return max(nums[0], nums[1]);
        else { // nums_size > 2
            // init condition
            data[0] = nums[0];
            data[1] = max(nums[0], nums[1]); // first and second
            compare_data[0] = nums[1];
            compare_data[1] = max(nums[1], nums[2]); // second and third
            for (int i = 2; i < nums_size - 1; i++) {
                data[i] = max(nums[i] + data[i - 2], data[i - 1]); // compare not including and including center value
                compare_data[i] = max(nums[i + 1] + compare_data[i - 2], compare_data[i - 1]); // same with above but from forward one index
            }
            return max(data[nums_size - 2], compare_data[nums_size - 2]);
        }
    }
};

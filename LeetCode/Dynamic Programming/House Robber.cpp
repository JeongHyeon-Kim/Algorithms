// problem source: https://leetcode.com/problems/house-robber/
// discussion reference: https://leetcode.com/problems/house-robber/submissions/
class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> data(nums_size, 0);

        // exception cases
        if (nums_size == 1)
            return nums[0];
        else if (nums_size == 2)
            return max(nums[0], nums[1]);
        else { // nums_size > 2
            // init condition
            data[0] = nums[0];
            int result = max(nums[0], nums[1]);
            int compare_value = 0;
            data[1] = result; // first max value
            for (int i = 2; i < nums_size; i++) { // increasing interval?
                if (compare_value < data[i - 2]) // get bigger value
                    compare_value = data[i - 2]; // interval is 2
                data[i] = nums[i] + compare_value; // including
                if (data[i] > result) // get bigger value
                    result = data[i];
            }
            return result;
        }

        // All PASS Presented Test Case, Wrong With [2,1,1,2]
        // int nums_size = nums.size();
        // int odd_result = 0, even_result = 0;
        //
        // for (int i = 0; i < nums_size; i++) {
        //     if (i % 2 == 0)
        //         even_result += nums[i];
        //     else
        //         odd_result += nums[i];
        // }
        // return max(odd_result, even_result);
    }
};

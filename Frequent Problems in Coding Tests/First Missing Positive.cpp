// problem source: https://leetcode.com/problems/first-missing-positive/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int nums_size = nums.size();
        bool checking[10000000] = {false};
        for (int i = 0; i < nums_size; i++) {
            if (nums[i] > 0 && nums[i] < 10000000)
                checking[nums[i]] = true;
        }
        for (int i = 1; i < 10000000; i++) {
            if (checking[i] == false)
                return i;
        }
        return 0;

        // Runtime Error with [2147483647]
        // int nums_size = nums.size();
        // bool checking[10000000] = {false};
        // for (int i = 0; i < nums_size; i++) {
        //     if (nums[i] > 0)
        //         checking[nums[i]] = true;
        // }
        // for (int i = 1; i < 10000000; i++) {
        //     if (checking[i] == false)
        //         return i;
        // }
        // return 0;
    }
};

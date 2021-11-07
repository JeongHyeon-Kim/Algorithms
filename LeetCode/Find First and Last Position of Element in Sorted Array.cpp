// problem source: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int nums_size = nums.size();
        int count = 0;
        bool prev_check = false;

        if (nums_size == 1) {
            if (nums[0] == target) {
                result[0] = 0;
                result[1] = 0;
            }
        } else {
            for (int i = 0; i < nums_size; i++) {
                if (nums[i] == target && count == 0) {
                    cout << i << ": in" << endl;
                    result[0] = i;
                    prev_check = true;
                    count++;
                    if (i == nums_size - 1) // last element
                        result[1] = nums_size - 1;
                } else if (nums[i] == target && (prev_check == true)) {
                    count++;
                    if (i == nums_size - 1) // last element
                        result[1] = nums_size - 1;
                } else if (nums[i] != target && prev_check) {
                    cout << i << ": in" << endl;
                    result[1] = i - 1;
                    prev_check = false;
                }

            }
        }
        return result;

        // Wrong With [1,4], 4
        // Wrong With [1,2,3], 1
        // vector<int> result = {-1, -1};
        // int nums_size = nums.size();
        // int count = 0;
        // bool prev_check = false;
        //
        // if (nums_size == 1) {
        //     if (nums[0] == target) {
        //         result[0] = 0;
        //         result[1] = 0;
        //     }
        // } else {
        //     for (int i = 0; i < nums_size; i++) {
        //         cout << (nums[i] == target) << endl;
        //         cout << (prev_check == true) << endl;
        //         if (nums[i] == target && count == 0) {
        //             result[0] = i;
        //             prev_check = true;
        //             count++;
        //         } else if (nums[i] == target && (prev_check == true)) {
        //             count++;
        //             if (i == nums_size - 1)
        //                 result[1] = nums_size - 1;
        //         } else if (nums[i] != target && prev_check)
        //             result[1] = i - 1;
        //
        //     }
        // }
        // return result;

        // Wrong With [2,2], 2
        // vector<int> result = {-1, -1};
        // int nums_size = nums.size();
        // int count = 0;
        // bool prev_check = false;
        //
        // if (nums_size == 1) {
        //     if (nums[0] == target) {
        //         result[0] = 0;
        //         result[1] = 0;
        //     }
        // } else {
        //     for (int i = 0; i < nums_size; i++) {
        //         if (nums[i] == target && count == 0) {
        //             result[0] = i - 1;
        //             prev_check = true;
        //         } else if (nums[i] == target && prev_check)
        //             count++;
        //         else if (nums[i] != target && prev_check)
        //             result[1] = i - 1;
        //     }
        // }
        // return result;

        // All PASS Presented Test Case, Wrong With [1], 1
        // vector<int> result = {-1, -1};
        // int nums_size = nums.size();
        // int count = 0;
        // bool prev_check = false;
        // for (int i = 0; i < nums_size; i++) {
        //     if (nums[i] == target && count == 0) {
        //         result[0] = i - 1;
        //         prev_check = true;
        //     } else if (nums[i] == target && prev_check)
        //         count++;
        //     else if (nums[i] != target && prev_check)
        //         result[1] = i - 1;
        // }
        // return result;
    }
};

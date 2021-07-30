// problem source: https://leetcode.com/problems/product-of-array-except-self/
// discussion reference: https://leetcode.com/problems/product-of-array-except-self/discuss/1371436/C%2B%2B-or-O(n)-time-O(1)-space-or-neat-and-clean
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> result(nums_size);
        for (int i = nums_size - 1; i >= 0; i--) { // multiply end element to begin element
            if (i == nums_size - 1)
                result[i] = nums[i];
            else
                result[i] = result[i + 1] * nums[i];
        }
        int prev = 1;
        for (int i = 0; i < nums_size; i++) { // multiply begin element to end element
            if (i == nums_size - 1)
                result[i] = prev;
            else
                result[i] = prev * result[i + 1];
            prev *= nums[i];
        }
        return result;

        // Wrong Answer with [0,0]
        // int nums_size = nums.size();
        // vector<int> result;
        // int middle = 1;
        // bool presenceZero = false;
        // for (int i = 0; i < nums_size; i++) {
        //     if (nums[i] != 0)
        //         middle *= nums[i];
        //     else
        //         presenceZero = true;
        // }
        // for (int i = 0; i < nums_size; i++) {
        //     if (presenceZero) {
        //         if (nums[i] == 0)
        //             result.push_back(middle);
        //         else
        //             result.push_back(0);
        //     } else {
        //         result.push_back(middle / nums[i]);
        //     }
        //
        // }
        // return result;

        // Time Limit Exceeded
        // int nums_size = nums.size();
        // vector<int> result;
        // for (int i = 0; i < nums_size; i++) {}
        //     int middle_result = 1;
        //     for (int j = 0; j < nums_size; j++) {
        //         if (i == j)
        //             continue;
        //         else
        //             middle_result *= nums[j];
        //     }
        //     result.push_back(middle_result);
        // }
        // return result;
    }
};

// problem source: https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> result;
        for (int i = 0; i < nums_size; i++) {
            cout << nums[i] << " ";
        }
        return result;
    }
};

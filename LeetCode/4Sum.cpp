// problem source: https://leetcode.com/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int nums_size = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < nums_size; i++)
            cout << nums[i] << " ";
        cout << endl;
        cout << target << endl;
        return result;
    }
};

// problem source: https://leetcode.com/problems/maximum-subarray/
// discussion reference: https://leetcode.com/problems/maximum-subarray/discuss/1299861/0-ms-oror-C%2B%2B-oror-0(n)-timeoror-o(1)-space
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int nums_size = nums.size();
        int comp = nums[0];
        int result = nums[0];
        for(int i = 1; i < nums_size; i++)
        {
            comp = max(nums[i] + comp, nums[i]);
            result = max(result, comp);
        }
        return result;
        // Time Limit Exceeded
        // int nums_size = nums.size();
        // int comp;
        // int max = INT_MIN;
        // for (int i = 0; i < nums_size; i++) {
        //     for (int j = i; j < nums_size; j++) {
        //         comp = 0;
        //         for (int k = i; k <= j; k++)
        //             comp += nums[k];
        //         cout << comp << endl;
        //         if (max < comp)
        //             max = comp;
        //     }
        // }
        // return max;
    }
};

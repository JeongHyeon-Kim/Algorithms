// problem source: https://leetcode.com/contest/weekly-contest-269/problems/k-radius-subarray-averages/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // All PASS Presented Test Case,  Time Limit Exceeded
        int nums_size = nums.size();
        vector<int> result;
        if (nums_size < k)
            return {-1};
        for (int i = 0; i < nums_size; i++) {
            if (i < k)
                result.push_back(-1);
            else if (i >= k && i + k < nums_size) {
                int sum = 0, count = 0;
                for (int j = i - k; j <= i + k; j++) {
                    sum += nums[j];
                    count++;
                }
                if (count != 0)
                    result.push_back(sum / count);
                else
                    result.push_back(nums[k]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};

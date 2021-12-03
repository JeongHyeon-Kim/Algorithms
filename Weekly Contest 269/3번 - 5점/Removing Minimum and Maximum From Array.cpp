// problem source: https://leetcode.com/contest/weekly-contest-269/problems/removing-minimum-and-maximum-from-array/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int nums_size = nums.size();
        int deletion_count = 0;
        int max_index, max_value = INT_MIN;
        int min_index, min_value = INT_MAX;
        for (int i = 0; i < nums_size; i++) {
            if (nums[i] < min_value) {
                min_value = nums[i];
                min_index = i;
            }
            if (nums[i] > max_value) {
                max_value = nums[i];
                max_index = i;
            }
        }
        int max_count = min(max_index + 1, abs(nums_size - max_index));
        int min_count = min(min_index + 1, abs(nums_size - min_index));
        cout << max_count << " " << min_count << endl;
        deletion_count = max_count + min_count;
        return deletion_count;
    }
};

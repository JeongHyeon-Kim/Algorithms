// problem source: https://leetcode.com/contest/weekly-contest-279/problems/sort-even-and-odd-indices-independently/
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int nums_size = nums.size();
        for (int i = 0; i < nums_size - 2; i++) {
            for (int j = i + 2; j < nums_size; j += 2) {
                if (i % 2 == 1) {
                    if (nums[i] < nums[j]) {
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                    }
                } else {
                    if (nums[i] > nums[j]) {
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                    }
                }
            }
        }
        return nums;
    }
};

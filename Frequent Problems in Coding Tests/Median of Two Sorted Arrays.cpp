// problem source: https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int num1_size = nums1.size(), num2_size = nums2.size();
        for (int i = 0; i < num1_size; i++)
            merged.push_back(nums1[i]);
        for (int i = 0; i < num2_size; i++)
            merged.push_back(nums2[i]);
        int merged_size = merged.size();
        sort(merged.begin(), merged.end());
        if (merged_size % 2 == 1)
            return merged[merged_size / 2];
        else
            return (merged[merged_size / 2 - 1] + merged[merged_size / 2]) / 2.0f;
    }
};

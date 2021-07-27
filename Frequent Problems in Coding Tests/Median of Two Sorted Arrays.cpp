// problem source: https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        int num1_size = nums1.size(), num2_size = nums2.size();
        for (int i = 0; i < num1_size; i++)
            cout << nums1[i] << " ";
        cout << endl;
        for (int i = 0; i < num2_size; i++)
            cout << nums2[i] << " ";
        return result;
    }
};

// problem source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nums_size = nums.size();
        map<int, int> data;
        for (int i = 0; i < nums_size; i++)
            data[nums[i]]++;
        nums.clear();
        for (auto element : data)
            nums.push_back(element.first);

        // Traverse Elements By Another Method
        // for (auto element : data) {
        //     cout << element.first << " " << element.second << endl;
        // }

        // Take 1 - Using Iteration
        // for (int i = 1; i < nums_size; i++) {
        //     if (nums[i - 1] == nums[i]) {
        //         int j = i;
        //         while (j < nums_size) {
        //             nums[j - 1] = nums[j];
        //             j++;
        //         }
        //     }
        // }
        // for (int i = 0; i < nums_size; i++) {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;

        return nums.size();
    }
};

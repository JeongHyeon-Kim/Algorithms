// problem source: https://leetcode.com/problems/delete-and-earn/
// discussion reference: https://leetcode.com/problems/delete-and-earn/discuss/109895/JavaC++-Clean-Code-with-Explanation
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // nums's range from 1 to 10000
        int max_range_index = 10001; // for setting to vector index difference
        vector<int> values(max_range_index, 0); // init vector to zero
        int include = 0, exclude = 0;

        for (int num : nums)
            values[num] += num; // num's sum, ex) 2,2,3,3,3,4 is values[3] = 9

        for (int i = 0; i < max_range_index; i++) {
            int include_i = exclude + values[i];
            int exclude_i = max(exclude, include);
            include = include_i;
            exclude = exclude_i;
        }

        return max(include, exclude);

        // Initial Code
        // int nums_size = nums.size();
        // int result = 0;
        // map<int, int> data_count; // number and count
        // for (int i = 0; i < nums_size; i++) {
        //     // cout << nums[i] << " ";
        //     data_count[nums[i]]++;
        // }
        // // cout << endl;
        //
        //
        // for (auto element : data_count) {
        //     // cout << element.first << " " << element.second << endl;
        //     while (!data_count.empty()) {
        //         if (result < element.first * element.second) {
        //             result = element.first * element.second;
        //         }
        //     }
        // }
        //
        // return result;
    }
};

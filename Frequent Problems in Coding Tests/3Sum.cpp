// problem source: https://leetcode.com/problems/3sum/
// discussion reference: https://leetcode.com/problems/3sum/discuss/1310898/Easy-to-understand-solution-in-C%2B%2B
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int nums_size = nums.size();
        vector<vector<int>> result;
        if (nums_size < 3)
            return {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums_size; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = nums_size - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else { // sum == 0
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) // for skip
                        j++;
                    while (j < k && nums[k] == nums[k - 1]) // for skip
                        k--;
                    j++;
                    k--;
                }
            }
        }
        return result;
        // Time Limit Exceeded 2
        // int nums_size = nums.size();
        // vector<vector<int>> result;
        // vector<pair<int, int>> middle_result;
        // for (int i = 0; i < nums_size - 1; i++) {
        //     for (int j = i + 1; j < nums_size; j++)
        //         middle_result.push_back(make_pair(i, j));
        // }
        // for (int i = 0; i < nums_size; i++) {
        //     for (auto it = middle_result.begin(); it != middle_result.end(); it++) {
        //         if (i != it->first && i != it->second && it->first != it->second) {
        //             if (nums[i] + nums[it->first] + nums[it->second] == 0) {
        //                 vector<int> insert;
        //                 insert.push_back(nums[i]);
        //                 insert.push_back(nums[it->first]);
        //                 insert.push_back(nums[it->second]);
        //                 sort(insert.begin(), insert.end());
        //                 auto it = find(result.begin(), result.end(), insert);
        //                 if (it == result.end())
        //                     result.push_back(insert);
        //             }
        //         }
        //     }
        // }
        // return result;

        // Time Limit Exceeded 1
        // int nums_size = nums.size();
        // vector<vector<int>> result;
        // vector<bool> check(nums_size);
        // for (int i = 0; i < nums_size - 2; i++) {
        //     for (int j = i + 1; j < nums_size - 1; j++) {
        //         for (int k = j + 1; k < nums_size; k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0) {
        //                 check[i] = true;
        //                 check[j] = true;
        //                 check[k] = true;
        //                 vector<int> insert;
        //                 insert.push_back(nums[i]);
        //                 insert.push_back(nums[j]);
        //                 insert.push_back(nums[k]);
        //                 sort(insert.begin(), insert.end());
        //                 auto it = find(result.begin(), result.end(), insert);
        //                 if (it == result.end())
        //                     result.push_back(insert);
        //             }
        //         }
        //     }
        // }
        // return result;
    }
};

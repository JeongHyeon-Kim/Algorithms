// problem source: https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Time Limit Exceeded
        int nums_size = nums.size();
        vector<vector<int>> result;
        vector<pair<int, int>> middle_result;
        for (int i = 0; i < nums_size - 1; i++) {
            for (int j = i + 1; j < nums_size; j++) {
                // cout << i << " " << j << endl;
                middle_result.push_back(make_pair(i, j));
            }
        }
        for (auto it = middle_result.begin(); it != middle_result.end(); it++) {
            cout << it->first << " " << it->second << endl;
        }
        for (int i = 0; i < nums_size; i++) {
            for (auto it = middle_result.begin(); it != middle_result.end(); it++) {
                if (i != it->first && i != it->second && it->first != it->second) {
                    if (nums[i] + nums[it->first] + nums[it->second] == 0) {
                        vector<int> insert;
                        insert.push_back(nums[i]);
                        insert.push_back(nums[it->first]);
                        insert.push_back(nums[it->second]);
                        sort(insert.begin(), insert.end());
                        auto it = find(result.begin(), result.end(), insert);
                        if (it == result.end())
                            result.push_back(insert);
                    }
                }
            }
        }
        return result;

        // Time Limit Exceeded
        int nums_size = nums.size();
        vector<vector<int>> result;
        vector<bool> check(nums_size);
        for (int i = 0; i < nums_size - 2; i++) {
            for (int j = i + 1; j < nums_size - 1; j++) {
                for (int k = j + 1; k < nums_size; k++) {
                    // cout << i << " " << j << " " << k << endl;
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        // cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
                        cout << i << " " << j << " " << k << endl;

                        check[i] = true;
                        check[j] = true;
                        check[k] = true;

                        vector<int> insert;

                        insert.push_back(nums[i]);
                        insert.push_back(nums[j]);
                        insert.push_back(nums[k]);
                        sort(insert.begin(), insert.end());
                        auto it = find(result.begin(), result.end(), insert);
                        if (it == result.end())
                            result.push_back(insert);
                    }
                }
            }
        }
        for (int i = 0; i < nums_size; i++) {
            // cout << check[i] << " ";
        }
        return result;
    }
};

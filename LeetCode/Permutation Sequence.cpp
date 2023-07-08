// problem source: https://leetcode.com/problems/permutation-sequence/

/*
순열에 대한 조합의 경우들을 vector에 저장하고 k-1 번째의 요소를 출력한다.
Time Limit Exceeded at 137 case 
n = 9, k = 161191
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<vector<int>> result;
        string int_to_string;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        result.push_back(nums);
        while(next_permutation(nums.begin(), nums.end()))
            result.push_back(nums);
        // for (int i = 0; i < result.size(); i++) {
        //     for (int j = 0; j < result[0].size(); j++)
        //         cout << result[i][j];
        //     cout << endl;
        // }
        for (int i = 0; i < n; i++)
            // cout << result[k-1][i];
            int_to_string += to_string(result[k-1][i]);
        return int_to_string;
    }
};
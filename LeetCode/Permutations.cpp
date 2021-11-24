// problem source: https://leetcode.com/problems/permutations/
// dicussion reference: https://mjmjmj98.tistory.com/38
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++)
            cout << nums[i] << " ";
        cout << endl;
        return result;
    }
};

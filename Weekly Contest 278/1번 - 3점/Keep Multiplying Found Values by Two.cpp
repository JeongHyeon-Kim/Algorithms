// problem souce: https://leetcode.com/contest/weekly-contest-278/problems/keep-multiplying-found-values-by-two/
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int nums_size = nums.size();
        while (true) {
            if (find(nums.begin(), nums.end(), original) != nums.end()) {
                original = original * 2;
            } else
                break;
        }
        return original;
    }
};

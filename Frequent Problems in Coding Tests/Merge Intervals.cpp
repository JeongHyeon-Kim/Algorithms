// problem source: https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int intervals_size = intervals.size();
        vector<vector<int>> result;
        vector<int> set;
        bool flag[10001] = {false, };

        for (int i = 0; i < intervals_size; i++) {
            for (int j = intervals[i][0]; j <= intervals[i][1]; j++)
                flag[j] = true;
        }

        for (int i = 1; i < 10001; i++) {
            if (!flag[i - 1] && flag[i]) // false -> true
                set.push_back(i);
            else if (flag[i - 1] && !flag[i]) { // true -> false
                set.push_back(i - 1);
                result.push_back(set);
                set.clear();
            } else
                continue;
        }
        return result;
    }
};

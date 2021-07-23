// problem source: https://leetcode.com/problems/merge-intervals/
// discussion reference: https://leetcode.com/problems/merge-intervals/discuss/1356951/C%2B%2B-easy-to-Understand
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int intervals_size = intervals.size();
        vector<vector<int>> result;
        vector<int> set;
        sort(intervals.begin(), intervals.end()); // ascending power
        set = intervals[0]; // insert first vector
        for (auto it : intervals) {
            if (set[1] >= it[0]) // set bigger number at second position
                set[1] = max(set[1], it[1]);
            else {
                result.push_back(set); // complete one set
                set = it;
            }
        }
        result.push_back(set);
        return result;
        // failed with [1,4], [5, 6]
        // int intervals_size = intervals.size();
        // vector<vector<int>> result;
        // vector<int> set;
        // bool flag[10001] = {false, };
        //
        // for (int i = 0; i < intervals_size; i++) {
        //     for (int j = intervals[i][0]; j <= intervals[i][1]; j++)
        //         flag[j] = true;
        // }
        //
        // for (int i = 1; i < 10001; i++) {
        //     if (!flag[i - 1] && flag[i]) // false -> true
        //         set.push_back(i);
        //     else if (flag[i - 1] && !flag[i]) { // true -> false
        //         set.push_back(i - 1);
        //         result.push_back(set);
        //         set.clear();
        //     } else
        //         continue;
        // }
        // return result;
    }
};

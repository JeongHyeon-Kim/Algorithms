// problem source: https://leetcode.com/problems/insert-interval/
// 기존의 간격 정보가 주어지고, 새로운 간격 정보가 주어지면 중복되는 것들을 합쳐서 하나로 만든다.
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int each_interval = intervals.size();
        for (int i = 0; i < each_interval; i++) {
            cout << intervals[i][0] << " " << intervals[i][1] << endl;
            if (intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0]) { // start point
                if (newInterval[1] > intervals[i][1])
                    intervals[i][1] = newInterval[1];
            } else if (intervals[i][0] <= newInterval[1] && intervals[i][1]>= newInterval[1]) {// end point
                if (newInterval[1] > interval[i][1])
                    intervals[i][1] = newInterval[1];
            }
        }
        cout << newInterval[0] << " " << newInterval[1] << endl;
        return intervals;
    }
};
// problem source: https://leetcode.com/problems/insert-interval/
// discussion reference: https://leetcode.com/problems/insert-interval/solutions/3059215/detailed-video-soultion-o-n-beats-99-solution-beginner-friendly/
// 기존의 간격 정보가 주어지고, 새로운 간격 정보가 주어지면 중복되는 것들을 합쳐서 하나로 만든다.
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int each_interval = intervals.size();
        int i = 0;
        // 끝점 기준 겹치지 않는 경우의 간격들은 다 넣는다.
        while (i < each_interval && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // 겹치는 경우에는 값을 비교하여 생성하고 넣는다.
        while (i < each_interval && intervals[i][0] <= newInterval[1]) {
            // 시작점은 더 작은 걸 기준으로
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            // 끝점은 더 큰 걸 기준으로 갱신
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        // 시작점, 끝점 모두 겹치지 않는 새로운 간격일 경우 그대로 넣는다.
        while (i < each_interval)
            result.push_back(intervals[i++]);

        return result;
        // middle solution of 'Insert Interval'
        // vector<vector<int>> result;
        // int each_interval = intervals.size();
        // for (int i = 0; i < each_interval; i++) {
        //     cout << intervals[i][0] << " " << intervals[i][1] << endl;
        //     if (intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0]) { // start point
        //         if (newInterval[1] > intervals[i][1])
        //             intervals[i][1] = newInterval[1];
        //     } else if (intervals[i][0] <= newInterval[1] && intervals[i][1]>= newInterval[1]) {// end point
        //         if (newInterval[1] > interval[i][1])
        //             intervals[i][1] = newInterval[1];
        //     }
        // }
        // cout << newInterval[0] << " " << newInterval[1] << endl;
        // return intervals;
    }
};
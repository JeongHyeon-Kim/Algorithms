// problem source: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int start_time_size = startTime.size();
        int end_time_size = endTime.size();
        int profit_size = profit.size();
        for (int i = 0; i < start_time_size; i++)
            cout << startTime[i] << " ";
        cout << endl;
        for (int i = 0; i < end_time_size; i++)
            cout << endTime[i] << " ";
        cout << endl;
        for (int i = 0; i < profit_size; i++)
            cout << profit[i] << " ";
        cout << endl;
        return 0;
    }
};

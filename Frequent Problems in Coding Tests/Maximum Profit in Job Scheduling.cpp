// problem source: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// discussion reference: https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/1457641/C++-solution-O(n2):easy-understandable-approach-for-beginners
class Solution {
public:
    typedef struct {
        int start_time;
        int end_time;
        int profit;
    }job_data;

    static bool compare(job_data &a, job_data &b) {
        return a.end_time < b.end_time;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int jobs_count = startTime.size();
        vector<job_data> jobs_data(jobs_count);
        for (int i = 0; i < jobs_count; i++) {
            jobs_data[i].start_time = startTime[i];
            jobs_data[i].end_time = endTime[i];
            jobs_data[i].profit = profit[i];
        }

        sort(jobs_data.begin(), jobs_data.end(), compare); // the later the end time, the more backwards

        int dynamic_programming[jobs_count];
        dynamic_programming[0] = jobs_data[0].profit;
        for (int i = 1; i < jobs_count; i++) {
            int present = jobs_data[i].profit;
            int past = -1;
            for (int j = i - 1; j >= 0; j--) {// going to backwards: 0, 1 0, 2 1 0
                if (jobs_data[j].end_time <= jobs_data[i].start_time) { // i's start_time comapare with j's end_time going to backwards
                    past = j; // and changing past value
                    break;
                }
            }
            if (past != -1) // after initial setting
                dynamic_programming[i] = max(dynamic_programming[i - 1], present + dynamic_programming[past]); // past maximum vs. present + past
            else // initial setting,  when past == -1
                dynamic_programming[i] = max(dynamic_programming[i - 1], present); // past maximum vs. present
        }
        return dynamic_programming[jobs_count - 1]; // optimal value at last location
    }
};

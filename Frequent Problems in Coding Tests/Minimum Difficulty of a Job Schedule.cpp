// problem source: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// discussion reference: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/discuss/1229524/C++-DFS-simple-solution.
class Solution {
public:
    int memoization[11][301] = {0, };
    int minDifficulty(vector<int>& jobDifficulty, int d, int current = 0) { // adding parameter for comparing
        int job_difficulty_size = jobDifficulty.size();
        int result = INT_MAX;
        int current_max_difficulty = 0;

        if (job_difficulty_size - current < d) // can't arrange per days
            return -1;

        if (memoization[d][current] != 0)
            return memoization[d][current];

        for (int i = current; i <= job_difficulty_size - d; i++) {
            // d is count of working day
            // maximum difficulty is set to difficulty in day
            current_max_difficulty = max(current_max_difficulty, jobDifficulty[i]); // get current max difficulty
            if (d > 1)
                result = min(result, minDifficulty(jobDifficulty, d - 1, i + 1) + current_max_difficulty); // comparaing previous max difficulty and next case
            else
                result = current_max_difficulty; // end, day value is decreased
        }
        memoization[d][current] = result;
        return result;
    }
};

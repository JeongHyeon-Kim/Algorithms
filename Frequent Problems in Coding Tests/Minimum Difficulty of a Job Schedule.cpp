// problem source: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int job_difficulty_size = jobDifficulty.size();
        for (int i = 0; i < job_difficulty_size; i++)
            cout << jobDifficulty[i] << " ";
        return d;
    }
};

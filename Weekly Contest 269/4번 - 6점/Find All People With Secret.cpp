// problem source: https://leetcode.com/contest/weekly-contest-269/problems/find-all-people-with-secret/
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        cout << n << endl;
        int meetings_size = meetings.size();
        vector<int> result;
        for (int i = 0; i < meetings_size; i++) {
            for (int j = 0; j < 3; j++)
                cout << meetings[i][j] << " ";
            cout << endl;
        }
        cout << firstPerson << endl;
        return result;
    }
};

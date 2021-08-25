// problem source: https://leetcode.com/problems/random-pick-with-weight/
class Solution {
public:
    Solution(vector<int>& w) {
        int w_size = w.size();
        for (int i = 0; i < w_size; i++)
            cout << w[i] << endl;
    }

    int pickIndex() {
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

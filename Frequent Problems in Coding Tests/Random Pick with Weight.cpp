// problem source: https://leetcode.com/problems/random-pick-with-weight/
// discussion reference: https://leetcode.com/problems/random-pick-with-weight/discuss/1492793/C++-Solution-or-O(nlogn)
class Solution {
public:
    int sum_of_weight = 0;
    vector<int> pre_sum;
    Solution(vector<int>& w) { // w is set of weights
        int w_size = w.size();
        for (int i = 0; i < w_size; i++) {
            sum_of_weight += w[i];
            pre_sum.push_back(sum_of_weight - 1);
        }
    }

    int pickIndex() {
        int pick = rand() % sum_of_weight;// if sum_of_weight is 4, temp can 0 ~ 3
        int index = lower_bound(pre_sum.begin(), pre_sum.end(), pick) - pre_sum.begin(); // Returning the index number of the first occurrence of a number 'pick' or higher while searching from array's begin to the end
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

// problem source: https://leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int digits_size = digits.size();
        vector<int> result(digits_size + 1);
        for (int i = digits_size; i >= 0; i--) { // traverse reverse
            cout << i << " ";
        }
        cout << endl;
        return result;
    }
};

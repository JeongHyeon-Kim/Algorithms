// problem source: https://leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int digits_size = digits.size();
        int is_carry = 10;
        vector<int> result(digits_size + 1);
        if (digits[digits_size - 1] + 1 != is_carry) {
            digits[digits_size - 1] += 1;
            return digits;
        } else {
            for (int i = digits_size; i >= 0; i--) { // reverse traversal
                if (i - 1 >= 0) { // adjust index
                    if (digits[i - 1] + 1 == is_carry) { // carrying condition
                        result[i - 1]++;
                        result[i] = 0;
                        digits[i - 1] = 0; // also, editing digits variable
                    } else { // using digits variable, not expand
                        digits[i - 1] = digits[i - 1] + 1;
                        return digits;
                    }
                }
            }
            return result;
        }
    }
};

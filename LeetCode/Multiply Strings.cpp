// problem source: https://leetcode.com/problems/multiply-strings/
class Solution {
public:
    string multiply(string num1, string num2) {
        // Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
        string result;
        int middle_result = stoi(num1) * stoi(num2);
        result = to_string(middle_result);
        return result;
    }
};

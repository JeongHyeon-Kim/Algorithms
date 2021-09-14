// problem source: https://leetcode.com/problems/palindrome-number/
class Solution {
public:
    bool isPalindrome(int x) {
        string data = to_string(x);
        int data_length = data.length();
        bool result = true;
        for (int i = 0; i < data_length / 2; i++) {
            if (data[i] != data[data_length - i - 1])
                result = false;
        }
        return result;
    }
};

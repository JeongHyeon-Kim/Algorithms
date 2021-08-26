// problem source: https://leetcode.com/problems/longest-palindromic-substring/
// discussion reference: https://leetcode.com/problems/longest-palindromic-substring/discuss/1417447/Non-DP-Easy-to-understand-C%2B%2B-solution
class Solution {
public:
    int getPalindromeLength(string s, int left_index, int right_index) {
        int s_length = s.length();
        if (right_index > s_length) // threshold of i + 1
            return 0;
        int length;
        if (left_index == right_index) // odd string
            length = -1;
        else // even string
            length = 0;
        while (left_index >= 0 && right_index < s_length) { // range of string
            if (s[left_index] != s[right_index]) // checking palindrome
                break;
            length += 2;
            left_index--; // expand to left
            right_index++; // expand to right
        }
        return length;
    }
    string longestPalindrome(string s) {
        int s_length = s.length(), start;
        string result;
        int max_length = 0;
        for (int i = 0; i < s_length; i++){
            int length = max(getPalindromeLength(s, i, i), getPalindromeLength(s, i, i + 1)); // odd and even string, change starting point
            if (length > max_length) {
                max_length = length;
                start = i - (max_length - 1) / 2;
            }
        }
        result = s.substr(start, max_length);
        return result;
    }
};

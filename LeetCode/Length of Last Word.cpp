// problem source: https://leetcode.com/problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int s_length = s.length();
        string middle_result;
        stringstream ss;
        ss.str(s);
        while (ss >> middle_result)
            ;
        return middle_result.length();
    }
};

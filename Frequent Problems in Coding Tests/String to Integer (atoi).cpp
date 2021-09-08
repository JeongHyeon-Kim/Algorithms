// problem source: https://leetcode.com/problems/string-to-integer-atoi/
// discussion reference: https://leetcode.com/problems/string-to-integer-atoi/discuss/1451020/simple-C%2B%2B-using-istringstream%3A
class Solution {
public:
    int myAtoi(string s) {
        istringstream data(s);
        int result = 0;
        data >> result;
        return result;
    }
};

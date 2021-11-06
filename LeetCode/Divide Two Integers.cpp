// problem source: https://leetcode.com/problems/divide-two-integers/
class Solution {
public:
    int divide(int dividend, int divisor) {
        long extend_dividend = dividend;
        long extend_divsor = divisor;
        int result;
        if (extend_dividend / extend_divsor > INT_MAX) result = INT_MAX;
        else if (extend_dividend / extend_divsor < INT_MIN) result = INT_MIN;
        else result = extend_dividend / extend_divsor;
        return result;
    }
};

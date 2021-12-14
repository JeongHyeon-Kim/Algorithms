// problem source: https://leetcode.com/problems/powx-n/
// discussion reference: https://leetcode.com/problems/powx-n/discuss/739646/C++-Iterative-vs.-Recursive-Bitwise-Solutions-Explained-100-Time-80-space
class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        while (n) {
            if (n % 2) {
                if (n > 0)
                    result = result * x;
                else
                    result = result / x;
            }
            x = x * x;
            n /= 2;
        }
        return result;

        // Time Limit Exceeded, Test Cases Passed, But Took Too Long.
        double result = 0;
        double middle_result = 1;
        int powered = abs(n);
        if (n == 0 || x == 1)
            return 1;
        if (x == -1) {
            if (powered % 2 == 1)
                return -1;
            else
                return 1;
        }
        if (x == 0 || n == INT_MIN)
            return 0;
        while(powered-->0)
            middle_result *= x;
        if (n < 0)
            result = 1 / middle_result;
        else // n > 0
            result = middle_result;
        return result;

        // Time Limit Exceeded With -1.00000, 2147483647
        double result = 0;
        double middle_result = 1;
        int powered = abs(n);
        if (x == 0 || n == INT_MIN)
            return 0;
        if (n == 0 || x == 1)
            return 1;
        while(powered-->0)
            middle_result *= x;
        if (n < 0)
            result = 1 / middle_result;
        else // n > 0
            result = middle_result;
        return result;

        // Wrong Answer With 2.00000, -2147483648
        double result = 0;
        double middle_result = 1;
        int powered = abs(n);
        if (x == 0)
            return 0;
        if (n == 0 || x == 1)
            return 1;
        while(powered-->0)
            middle_result *= x;
        if (n < 0)
            result = 1 / middle_result;
        else // n > 0
            result = middle_result;
        return result;

        // All PASS Presented Test Cases, Time Limit Exceeded With 1.00000, 2147483647
        double result = 0;
        double middle_result = 1;
        int powered = abs(n);
        if (x == 0)
            return 0;
        while(powered-->0)
            middle_result *= x;
        if (n < 0)
            result = 1 / middle_result;
        else if (n == 0)
            return 1;
        else // n > 0
            result = middle_result;
        return result;
    }
};

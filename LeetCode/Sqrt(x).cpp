// problem source: https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
        int result;
        if (x == 0)
            result = 0;
        else if (x == 1)
            result = 1;
        else {
            for (long long i = 1; i <= x; i++) {
                if (i * i > x) {
                    result = i - 1;
                    break;
                }
            }
        }
        return result;
    }
};

// problem source: https://leetcode.com/problems/fibonacci-number/
class Solution {
public:
    int recursion_method(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        return recursion_method(n - 1) + recursion_method(n - 2);
    }

    int fib(int n) {
        return recursion_method(n);
    }
};

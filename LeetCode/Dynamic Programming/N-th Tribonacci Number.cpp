// problem source: https://leetcode.com/problems/n-th-tribonacci-number/
// discussion reference: https://leetcode.com/problems/n-th-tribonacci-number/discuss/1575588/C++-Easy-Solution-or-DP-or-100-Faster
class Solution {
public:
    int tribonacci(int n) {
        if(n < 2)
            return n;
        if(n == 2)
            return 1;

        int first = 0;
        int second = 1;
        int third = 1;
        int next_fibonacci = 0;
        for(int i = 3; i <= n; i++){
            next_fibonacci = first + second + third;
            first = second;
            second = third;
            third = next_fibonacci;
        }
        return next_fibonacci;

    // All PASS Presented Test Case, Time Limit Exceeded
    // int recursion_method(int n) {
    //     if (n == 0)
    //         return 0;
    //     if (n == 1)
    //         return 1;
    //     if (n == 2)
    //         return 1;
    //     return recursion_method(n - 1) + recursion_method(n - 2) + recursion_method(n - 3);
    // }
    // int tribonacci(int n) {
    //     return recursion_method(n);
    // }
};

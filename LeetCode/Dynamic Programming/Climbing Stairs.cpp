// problem source: https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        int first = 1;
        int second = 2;
        int distinct_ways = 0;
        for(int i = 2; i < n; i++){
            distinct_ways = first + second;
            first = second;
            second = distinct_ways;
        }
        return distinct_ways;
    }
};

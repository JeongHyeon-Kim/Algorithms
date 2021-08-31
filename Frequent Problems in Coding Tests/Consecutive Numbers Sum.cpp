// problem source: https://leetcode.com/problems/consecutive-numbers-sum/
// discussion reference: https://leetcode.com/problems/consecutive-numbers-sum/discuss/1411467/C%2B%2B-ez-Solution
class Solution {
public:
    int sumOfDigit(int n) {
        return n * (n + 1) / 2; // consecutive multiplication's half
    }
    int consecutiveNumbersSum(int n) {
      int count = 1;
      int length = sqrt(2 * n);
      for (int i = 2; i <= length; i++) {
          if ((n - sumOfDigit(i - 1)) % i == 0) // remainder is zero
              count++;
      }
      return count;
      // Time Limit Exceeded
      // int count = 1;
      // for (int i = 1; i < n; i++) {
      //     int start = i, target = n;
      //     while (target - start > 0) {
      //         target = target - start;
      //         start++;
      //     }
      //     if (target - start == 0)
      //         count++;
      // }
      // return count;
    }
};

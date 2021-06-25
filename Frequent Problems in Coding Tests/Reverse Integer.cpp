// problem source: https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    long reverse(long x) {
        vector<int> reverse;
        long result = 0;
        if (x > 0) {
            while (x != 0) {
                reverse.push_back(x % 10);
                x = x / 10;
            }
            int reverse_size = reverse.size();
            for (int i = 0; i < reverse_size; i++) {
                try {
                    result += reverse[i] * pow(10, reverse_size - i - 1);
                    if (INT_MAX < result)
                        throw 0;
                } catch (int result) {
                    return 0;
                }
            }
            return result;
        } else if (x < 0) {
            x = -x;
            while (x != 0) {
                reverse.push_back(x % 10);
                x = x / 10;
            }
            int reverse_size = reverse.size();
            for (int i = 0; i < reverse_size; i++){
                try {
                    result += reverse[i] * pow(10, reverse_size - i - 1);
                    if (INT_MAX < result)
                        throw 0;
                } catch (int result) {
                    return 0;
                }
            }
            return -(result);

        } else // x == 0
            return x;
    }
};

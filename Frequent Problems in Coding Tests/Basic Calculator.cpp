// problem source: https://leetcode.com/problems/basic-calculator/
class Solution {
public:
    int calculate(string s) {
        // Wrong Answer with "2147483647"
        int s_length = s.length();
        int result = 0;
        bool first = true;
        bool plusOrMinus = false; // false is plus, true is minus
        for (int i = 0; i < s_length; i++) {
            cout << s[i] << " " << (int)s[i]<< endl;
            int operand;
            if (s[i] >= 48 && s[i] <= 58) { // digit
                if (first) {
                    operand = s[i] - 48;
                    result += operand;
                    first = false;
                } else {
                    operand = s[i] - 48;
                    if (plusOrMinus)
                        result -= operand;
                    else
                        result += operand;
                }
            } else if (s[i] == 43) // plus
                plusOrMinus = false;
            else if (s[i] == 45) // minus
                plusOrMinus = true;
            else // blank
                continue;
        }
        return result;
    }
};

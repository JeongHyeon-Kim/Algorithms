// problem source: https://leetcode.com/problems/basic-calculator/
// discussion reference: https://leetcode.com/problems/basic-calculator/discuss/1372729/C%2B%2B-oror-Easy-to-undertand
class Solution {
public:
    int calculate(string s) {
        int s_length = s.length();
        int result = 0;
        stack<int> data;
        int sign = 1; // 1: plus, -1: minus
        for(int i = 0; i < s_length; i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                int val = 0;
                while (i < s_length && isdigit(s[i])) {
                    val = val * 10 + (s[i] - '0'); // multi-digit number
                    i++;
                }
                i--;
                val = val * sign;
                result += val;
                sign = 1;
            } else if(ch == '('){
                data.push(result); // stored previous result
                data.push(sign); // stored previous sign
                result = 0;
                sign = 1;
            } else if(ch== ')') {
                int top_data = data.top();
                data.pop();
                result *= top_data; // apply previous sign
                top_data = data.top();
                data.pop();
                result += top_data; // get previous result
            } else if(ch=='-')
                sign *= -1;
            else // blank
                continue;
        }
        return result;

        // Wrong Answer with "- (3 + (4 + 5))"
        // int s_length = s.length();
        // int result = 0;
        // stack<int> data;
        // int sign = 1;
        // for(int i = 0; i < s_length; i++) {
        //     char ch = s[i];
        //     if (isdigit(ch)) {
        //         int val = 0;
        //         while (i < s_length && isdigit(s[i])) {
        //             val = val * 10 + (s[i] - '0'); // multi-digit number
        //             i++;
        //         }
        //         i--;
        //         val = val * sign;
        //         result += val;
        //         sign = 1;
        //     } else if(ch=='-')
        //         sign *= -1;
        //     else // blank or bracket
        //         continue;
        // }
        // return result;

        // Wrong Answer with "2147483647"
        // int s_length = s.length();
        // int result = 0;
        // bool first = true;
        // bool plusOrMinus = false; // false is plus, true is minus
        // for (int i = 0; i < s_length; i++) {
        //     cout << s[i] << " " << (int)s[i]<< endl;
        //     int operand;
        //     if (s[i] >= 48 && s[i] <= 58) { // digit
        //         if (first) {
        //             operand = s[i] - 48;
        //             result += operand;
        //             first = false;
        //         } else {
        //             operand = s[i] - 48;
        //             if (plusOrMinus)
        //                 result -= operand;
        //             else
        //                 result += operand;
        //         }
        //     } else if (s[i] == 43) // plus
        //         plusOrMinus = false;
        //     else if (s[i] == 45) // minus
        //         plusOrMinus = true;
        //     else // blank
        //         continue;
        // }
        // return result;
    }
};

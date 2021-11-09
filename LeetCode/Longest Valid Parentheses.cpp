// problem source: https://leetcode.com/problems/longest-valid-parentheses/
// discussion reference: https://leetcode.com/problems/longest-valid-parentheses/discuss/1556913/C++-O(n)-solution-that-beats-100-Intuitive-implementation!
class Solution {
public:
    int longestValidParentheses(string s) {
        int s_length = s.length();
        stack<int> data;
        data.push(-1); // Base Value Initialization
        int result = 0;
        for (int i = 0; i < s_length; i++) {
            if (data.size() != 1 && s[i] == ')' && s[data.top()] == '(') { // data.size() != 1 Is Preventing Underflow
                data.pop();
                result = max(result, i - data.top());
                continue;
            }
            data.push(i);
        }
        return result;

        // Wrong With ")()())()()("
        int s_length = s.length();
        stack<char> data;
        int middle_result = 0;
        int sub_result = 0;
        int result = 0;
        bool prev_check = true;
        for (int i = 0; i < s_length; i++) {
            if (s[i] == '(')
                data.push(s[i]);
            else {// s[i] == ')'
                if (!data.empty() && data.top() == '(') {
                    data.pop();
                    middle_result += 2;
                    if (data.empty()) { // Valid Parentheses
                        result += middle_result;
                        middle_result = 0; // Init Middle Result For Next Valid Parentheses
                    } else
                        sub_result = middle_result;
                }
            }
        }
        return result > sub_result ? result : sub_result;

        // All PASS Presented Test Case
        int s_length = s.length();
        stack<char> data;
        int result = 0;
        for (int i = 0; i < s_length; i++) {
            // cout << s[i] << endl;
            if (s[i] == '(')
                data.push(s[i]);
            else {// s[i] == ')'
                if (!data.empty() && data.top() == '(') { // Valid Parentheses
                    data.pop();
                    result += 2;
                } else
                    continue;
            }
        }
        return result;
    }
};

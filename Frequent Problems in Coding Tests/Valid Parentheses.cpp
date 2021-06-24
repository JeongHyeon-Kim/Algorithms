// problem source: https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        int s_size = s.size();
        for (int i = 0; i < s_size; i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                parentheses.push(s[i]);
            } else if (s[i] == ')') {
                if (!parentheses.empty() && parentheses.top() == '(')
                    parentheses.pop();
                else
                    parentheses.push(s[i]);
            } else if (!parentheses.empty() && s[i] == '}') {
                if (parentheses.top() == '{')
                    parentheses.pop();
                else
                    parentheses.push(s[i]);
            } else { // ']'
                 if (!parentheses.empty() && parentheses.top() == '[')
                    parentheses.pop();
                else
                    parentheses.push(s[i]);
            }
        }
        if (parentheses.empty())
            return true;
        else
            return false;
    }
};

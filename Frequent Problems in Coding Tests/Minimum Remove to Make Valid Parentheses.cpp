// problem source: https: //leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// discussion reference: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/1381180/Stack-oror-faster-than-98.02-of-C%2B%2B-online-submissions
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> s_index;
        int s_length = s.length();
        for (int i = 0; i < s_length; i++) {
            if (s[i] == '(')
                s_index.push(i);
            else if (s[i] == ')') {
                if (!s_index.empty())
                    s_index.pop();
                else
                    s[i] = '*';
            }
        }
        while (!s_index.empty()) {
            s[s_index.top()] = '*';
            s_index.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end()); // erase(start, end), remove(begin, end, comp)
        return s;
    }
};

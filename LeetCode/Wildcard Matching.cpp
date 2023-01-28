class Solution {
public:
    bool isMatch(string s, string p) {
        // cout << s << " " << p << endl;
        int s_length = s.length();
        int p_length = p.length();
        vector<bool> matching_check(s_length);
        // pattern에 대한 parsing
        for (int i = 0; i < p_length; i++) {
            // cout << p[i] << " ";
            if (p[i] == '?') {
                cout << p[i] << " is single character" << endl;
                matching_check[i] = true;
            } else if (p[i] == '*') {
                cout << p[i] << " is any sequence of characters" << endl;
                for (int j = i; j < s_length; j++) {
                    if (p[j] != '*' || p[j] != '?')
                        matching_check[j] = true;
                }
            } else {
                cout << p[i] << " is normal character" << endl;
                if (s[i] != p[i])
                    return false;
                else
                    matching_check[i] = true;
            }
        }
        for (int i = 0; i < s_length; i++) {
            if (matching_check[i])
                continue;
            else
                return false;
        }
        return true;
    }
};

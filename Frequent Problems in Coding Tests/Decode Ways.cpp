// problem source: https://leetcode.com/problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        char alphabet[27] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; // unordererd_map
        if (stoi(s) == 0)
            return 0;
        int s_length = s.length();
        int count = 0;
        for (int i = 0; i < s_length; i++) {
            // cout << s[i] << " ";
            string temp;
            temp = s.substr(i, 1);
            // cout << temp << endl;
            int decoded = stoi(temp);
            if (decoded > 0 && decoded < 27) {
                cout << decoded << " ";
                count++;
            }
        }
        return 0;
    }
};

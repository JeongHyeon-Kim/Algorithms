// problem source: https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        vector<string> data(numRows);
        int s_length = s.length();
        int index = 0;
        if (numRows == 1)
            return s;
        for (int i = 0; i < s_length; i++) { // 0 1 2 3 4 5 6 7 8 9 ...
            // cout << index << endl;
            data[index].append(1, s[i]);
            if ( (i / (numRows - 1)) % 2 == 0) // 0 1 2 3 2 1 0 1 2 3 ...
                index++;
            else // (i / numRows - 1) % 2 == 1
                index--;
        }
        for (int i = 0; i < numRows; i++) {
            cout << data[i] << endl;
            result.append(data[i]);
        }
        return result;
    }
};

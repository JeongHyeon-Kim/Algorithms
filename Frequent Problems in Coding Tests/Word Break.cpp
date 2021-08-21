// problem source: https://leetcode.com/problems/word-break/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int dict_size = wordDict.size();
        cout << s << endl;
        for (int i = 0; i < dict_size; i++)
            cout << wordDict[i] << endl;
        return true;
    }
};

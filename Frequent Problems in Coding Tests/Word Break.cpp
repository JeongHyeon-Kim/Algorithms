// problem source: https://leetcode.com/problems/word-break/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Wrong Answer with "cars", ["car","ca","rs"]'
        int dict_size = wordDict.size();
        for (int i = 0; i < dict_size; i++) {
            auto pos = s.find(wordDict[i]);
            while (pos != std::string::npos) { // found
                s = s.erase(pos, wordDict[i].length());
                pos = s.find(wordDict[i]);
            }
        }
        if (s.length() == 0)
            return true;
        else
            return false;
    }
};

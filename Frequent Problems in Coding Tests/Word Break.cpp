// problem source: https://leetcode.com/problems/word-break/
// discussion reference: https://leetcode.com/problems/word-break/discuss/1486612/c++-memo-0ms
class Solution {
public:
    // Time Limit Exceeded with "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
    bool recursive_solving(string s, vector<string>& wordDict, int index, vector<bool> dynamic_programming) {
        int s_length = s.length();
        int dict_size = wordDict.size();

        if (index == s_length)
            return true;

        if (dynamic_programming[index])
            return false;

        for (int i = 0; i < dict_size; i++) {
            int word_length = wordDict[i].length();
            if ((s_length - index) >= word_length && s.substr(index, word_length) == wordDict[i]) {
                // sub word search in string length alphabetically
                // search sub string in wordDict
                if (recursive_solving(s, wordDict, index + word_length, dynamic_programming))
                    return true;
            }
        }

        dynamic_programming[index] = true; // not found
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dynamic_programming(s.length(), false);
        return recursive_solving(s, wordDict, 0, dynamic_programming);
    }

    // Wrong Answer with "cars", ["car","ca","rs"]'
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     int dict_size = wordDict.size();
    //     for (int i = 0; i < dict_size; i++) {
    //         auto pos = s.find(wordDict[i]);
    //         while (pos != std::string::npos) { // found
    //             s = s.erase(pos, wordDict[i].length());
    //             pos = s.find(wordDict[i]);
    //         }
    //     }
    //     if (s.length() == 0)
    //         return true;
    //     else
    //         return false;
    // }
};

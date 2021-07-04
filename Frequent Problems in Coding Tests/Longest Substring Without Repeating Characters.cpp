// problem source: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// discussion reference: https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1314865/c%2B%2B-easy-approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int current_length = 0;
        int maximum_length = 0;
        int substring_length = 0;
        unordered_map<char,int> mapping;
        while(j <= s.length()) {
            char ch = s[j];
            if (mapping.count(ch) and mapping[ch] >= i) { // ch is present char
                i = mapping[ch] + 1;
                current_length = j - i;
            }
            mapping[ch] = j;
            current_length++;
            j++;
            if (current_length > maximum_length) {
                maximum_length = current_length;
                substring_length = i;
            }
        }
        string res = s.substr(substring_length, maximum_length);
        return res.size();
        // fail with "dvdf" (not checking vdf)
        // int s_size = s.size();
        // int max_length = 0;
        // vector<char> repeat_check;
        // for (int i = 0; i < s_size; i++) {
        //     if (i == 0) {
        //         repeat_check.push_back(s[0]);
        //         max_length++;
        //     } else {
        //         auto it = find(repeat_check.begin(), repeat_check.end(), s[i]);
        //         if (it != repeat_check.end()) {
        //             if (max_length < repeat_check.size())
        //                 max_length = repeat_check.size();
        //             repeat_check.clear();
        //             repeat_check.push_back(s[i]);
        //         } else
        //             repeat_check.push_back(s[i]);
        //     }
        // }
        // if (max_length < repeat_check.size())
        //     max_length = repeat_check.size();
        // return max_length;
    }
};

// problem source: https://leetcode.com/problems/longest-common-prefix/
// error correction reference: https://stackoverflow.com/questions/37767847/stdsort-function-with-custom-compare-function-results-error-reference-to-non
class Solution {
public:
    static bool cmp(string first, string second) {
        return first.length() < second.length();
    }

    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int strs_size = strs.size();
        if (strs_size == 1)
            return strs[0];
        sort(strs.begin(), strs.end(), cmp);
        for (int i = 1; i <= strs[0].size(); i++) {
            string base_string = strs[0].substr(0, i);
            int count = 0;
            for (int j = 1; j < strs_size; j++) {
                string comp_string = strs[j].substr(0, i);
                if (base_string == comp_string)
                    count++;
                if (count == strs_size - 1)
                    result = base_string;
            }
        }
        return result;
    }
};

// problem source: https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        vector<pair<string, int>> mapping;
        mapping.push_back(make_pair("CM", 900));
        mapping.push_back(make_pair("CD", 400));
        mapping.push_back(make_pair("XC", 90));
        mapping.push_back(make_pair("XL", 40));
        mapping.push_back(make_pair("IX", 9));
        mapping.push_back(make_pair("IV", 4));
        mapping.push_back(make_pair("M", 1000));
        mapping.push_back(make_pair("D", 500));
        mapping.push_back(make_pair("C", 100));
        mapping.push_back(make_pair("L", 50));
        mapping.push_back(make_pair("X", 10));
        mapping.push_back(make_pair("V", 5));
        mapping.push_back(make_pair("I", 1));

        int mapping_size = mapping.size();
        while (s.length() != 0) {
            for (int i = 0; i < mapping_size; i++) {
                if (s.substr(0, mapping[i].first.length()) == mapping[i].first) {
                    result += mapping[i].second;
                    s = s.substr(mapping[i].first.length(), s.length() - 1);
                    break;
                }
            }
        }
        return result;
    }
};

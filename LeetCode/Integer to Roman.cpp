// problem source: https://leetcode.com/problems/integer-to-roman/
class Solution {
public:
    string intToRoman(int num) {
        string result;
        vector<pair<string, int>> mapping;
        mapping.push_back(make_pair("M", 1000));
        mapping.push_back(make_pair("CM", 900));
        mapping.push_back(make_pair("D", 500));
        mapping.push_back(make_pair("CD", 400));
        mapping.push_back(make_pair("C", 100));
        mapping.push_back(make_pair("XC", 90));
        mapping.push_back(make_pair("L", 50));
        mapping.push_back(make_pair("XL", 40));
        mapping.push_back(make_pair("X", 10));
        mapping.push_back(make_pair("IX", 9));
        mapping.push_back(make_pair("V", 5));
        mapping.push_back(make_pair("IV", 4));
        mapping.push_back(make_pair("I", 1));

        int mapping_size = mapping.size();
        while (num != 0) {
            for (int i = 0; i < mapping_size; i++) {
                if (num - mapping[i].second >= 0) {
                    basic_string<char> convert_char(mapping[i].first);
                    result.append(convert_char);
                    num = num - mapping[i].second;
                    break;
                }
            }
        }
        return result;
    }
};

// problem source: https://leetcode.com/problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int middle_result = stoi(a, NULL, 2) + stoi(b, NULL, 2);
        result = bitset<8>(middle_result).to_string();
        return result;
    }
};

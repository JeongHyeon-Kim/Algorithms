// problem source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    // wrong with more than three digits (ex. 234, 2345)
    vector<pair<char, string>> data;
    void init() {
        data.push_back(make_pair('2', "abc"));
        data.push_back(make_pair('3', "def"));
        data.push_back(make_pair('4', "ghi"));
        data.push_back(make_pair('5', "jkl"));
        data.push_back(make_pair('6', "mno"));
        data.push_back(make_pair('7', "pqrs"));
        data.push_back(make_pair('8', "tuv"));
        data.push_back(make_pair('9', "wxyz"));
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> letter_set;
        int digits_length = digits.length();
        if (digits_length == 0)
            return result;
        init();
        for (int i = 0; i < digits_length; i++) {
            for (int j = 0; j < 8; j++) {
                if (digits[i] == data[j].first)
                    letter_set.push_back(data[j].second);
            }
        }
        int letter_set_size = letter_set.size();
        int total_count = 1;
        for (int i = 0; i < letter_set_size; i++)
            total_count *= letter_set[i].size();

        for (int j = 0; j < letter_set[0].size(); j++) {
            int cycle = total_count / letter_set[0].size();
            for (int k = 0; k < cycle; k++) {
                string temp;
                temp += letter_set[0][j];
                result.push_back(temp);
            }
        }

        int index = 0;
        for (int i = 1; i < letter_set_size; i++) {
            int cycle = total_count / letter_set[i].size();
            for (int k = 0; k < cycle; k++) {
                for (int j = 0; j < letter_set[i].size(); j++) {
                    result[index % total_count] += letter_set[i][j];
                    index++;
                }
            }
        }

        return result;
    }
};

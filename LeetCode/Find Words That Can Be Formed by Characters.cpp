// problem source: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
// Runtime: 386 ms, faster than 9.68% of C++ online submissions for Find Words That Can Be Formed by Characters.
// Memory Usage: 51.6 MB, less than 17.58% of C++ online submissions for Find Words That Can Be Formed by Characters.
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int words_size = words.size();
        int chars_length = chars.length();
        unordered_map<char, int> count_per_alphabet;
        int result = 0;
        for (int i = 0; i < chars_length; i++)
            count_per_alphabet[chars[i]]++;
        for (int i = 0; i < words_size; i++) {
            string individual_word = words[i];
            int individual_word_size = words[i].size();
            unordered_map<char, int> temp_count_per_alphabet;
            bool all_found = true;
            int temp_result = 0;
            for (int j = 0; j < individual_word_size; j++)
                temp_count_per_alphabet[individual_word[j]]++;
            for (auto it = temp_count_per_alphabet.begin(); it != temp_count_per_alphabet.end(); it++) {
                auto found_location = count_per_alphabet.find(it->first);
                if (found_location != count_per_alphabet.end() && it->second <= found_location->second) {
                    temp_result += it->second;
                } else
                    all_found = false;
            }
            if (all_found)
                result += temp_result;
        }
        return result;
    }
};

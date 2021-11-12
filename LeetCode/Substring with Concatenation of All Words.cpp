// problem source: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// discussion reference: https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/1543058/C++-100
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // cout << s << endl;
        vector<int> result;
        unordered_map<string, int> word_count;
        int s_length = s.length();
        int words_size = words.size();
        int individual_word_length = words[0].length(); // all word has the same length

        if (s_length == 0 || words_size == 0)
            return result;

        for (string word : words)
            word_count[word]++;

        for (int i = 0; i < individual_word_length; i++) { // word's alphabet
            int starting_index = i, ending_index = i, found_word_count = 0;
            unordered_map<string, int> word_count_for_searching;
            while (ending_index + individual_word_length <= s_length) { // word's location move in s
                string target = s.substr(ending_index, individual_word_length); // get word
                ending_index += individual_word_length; // set ending index
                if (word_count.count(target) == 0) {// word not exist
                    found_word_count = 0; // init because exact once condition
                    word_count_for_searching.clear(); // also init
                    starting_index = ending_index; // move
                } else { // word exist
                    word_count_for_searching[target]++; // increase found count
                    found_word_count++;
                    while (word_count_for_searching[target] > word_count[target]) { // more than data's count
                        string rollback_target = s.substr(starting_index, individual_word_length); // get word
                        starting_index += individual_word_length; // next word
                        word_count_for_searching[rollback_target]--; // rollback
                        found_word_count--; // also rollback
                    }
                    if (found_word_count == words_size) // satisfy problem's condition
                        result.push_back(starting_index);
                }
            }
        }
        return result;

        // Take - 1
        // vector<int> result;
        // cout << s << endl;
        // int words_size = words.size();
        // vector<bool> checking(words_size);
        // int s_length = s.length();
        // int count = 0;
        // bool prev_check = true; // for first matching
        // for (int i = 0; i < s_length; i++) {
        //     if (words_size == 1) {
        //         int word_size = words[0].size();
        //         if (s.substr(i, word_size) == words[0]) {
        //             cout << "found" << endl;
        //             checking[0] = true;
        //             result.push_back(i); // first location
        //             i += word_size - 1;
        //         }
        //     } else { // words_size > 1
        //         for (int j = 0; j < words_size; j++) {
        //             cout << s.substr(i, words[j].size()) << " " << words[j] << endl;
        //             int word_size = words[j].size();
        //             if (s.substr(i, word_size) == words[j] && checking[j] == false && prev_check) { // found consecutive words and first matching
        //                 cout << "found" << endl;
        //                 checking[j] = true;
        //                 if (count == 0) { // first location
        //                     result.push_back(i);
        //                     count++;
        //                     prev_check = true;
        //                 } else { //  one or more words
        //                     // cout << count << endl;
        //                         count++;
        //                 }
        //                 i += word_size - 1;
        //                 break;
        //             } else { // not consecutive words
        //                 cout << "not" << endl;
        //                 for (int k = 0; k < words_size; k++)
        //                     checking[k] = false;
        //                 count = 0;
        //                 prev_check = false;
        //             }
        //         }
        //     }
        //     if (count == words_size) {
        //         cout << count << ": accepted" << endl;
        //         for (int i = 0; i < words_size; i++)
        //             checking[i] = false;
        //         count = 0;
        //     }

            // Initial Code
            // int check_count = 0;
            // for (int i = 0; i < words_size; i++) {
            //     if (checking[i])
            //         check_count++;
            // }
            // if (check_count == words_size) {
            //     cout << "accepted" << endl;
            //     for (int i = 0; i < words_size; i++)
            //         checking[i] = false;
            //     count = 0;
            // }

        // }
        //
        // return result;
    }
};

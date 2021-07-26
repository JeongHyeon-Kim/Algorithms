// problem source: https://leetcode.com/problems/text-justification/
// discussion reference: https://leetcode.com/problems/text-justification/discuss/1235203/C%2B%2B
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;

        if (words.empty()) // exception
            return result;

        int i = 0;
        int j = 1;
        int len = words[0].length();
        int l = 0;
        for (int n = 1; n < words.size(); n++) {
            for (; n < words.size() && len + words[n].length() < maxWidth; n++) {
                words[n - 1] += ' ';
                len += (words[n].length() + 1);
                j++;
            }

            if (n >= words.size()) break;
            for (int x = maxWidth - len, k = 0; x > 0; x--, k++) {
                if (k >= j - 1) k = 0;
                words[l + k] += ' ';
            }

            result.push_back("");

            for (int k = l; k < l + j; k++)
                result.back() += words[k];
            l = n;
            len = words[n].length();
            j = 1;
        }
        // handle the last string
        result.push_back("");
        for(int k = l; k < l + j; k++)
            result.back() += words[k];

        while (result.back().length() < maxWidth)
            result.back() += ' ';

        return result;
        // basic code
        // // vector<string> result;
        // int words_size = words.size();
        // int total_words_length = 0;
        // vector<string> selected_words;
        // string append_string;
        // for (int i = 0; i < words_size; i++) { // fully justified
        //     // cout << words[i] << " ";
        //     cout << words[i].size() << " ";
        //     total_words_length += words[i].size();
        //     if (total_words_length + 2 <= maxWidth) {
        //         append_string.append(words[i]);
        //         append_string.append("  ");
        //         total_words_length += 2;
        //         cout << append_string << endl;
        //     } else {
        //         selected_words.push_back(append_string);
        //         total_words_length = 0;
        //         append_string.clear();
        //         append_string.push_back(words[i]);
        //     }
        // }
        // return selected_words;
        // }
    }
};

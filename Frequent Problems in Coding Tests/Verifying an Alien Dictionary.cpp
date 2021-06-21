// problem source: https://leetcode.com/problems/verifying-an-alien-dictionary/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int words_size = words.size();
        unordered_map<char, int> mapping;
        int order_size = order.size();
        int pass_count = 1;
        for (int i = 0; i < order_size; i++)
            mapping[order[i]] = i;
        for (int i = 0; i < words_size - 1; i++) {
            int current_size = words[i].size();
            int next_size = words[i + 1].size();
            if (current_size > next_size) {
                for (int j = 0; j < current_size; j++) {
                    if (mapping[words[i][j]] > mapping[words[i + 1][j]])
                        return false;
                    else if (mapping[words[i][j]] == mapping[words[i + 1][j]])
                        continue;
                    else {
                        pass_count++;
                        break;
                    }
                }
            } else if (current_size < next_size) {
                for (int j = 0; j < next_size; j++) {
                    if (mapping[words[i][j]] > mapping[words[i + 1][j]])
                        return false;
                    else if (mapping[words[i][j]] == mapping[words[i + 1][j]])
                        continue;
                    else {
                        pass_count++;
                        break;
                    }
                }
            } else {
                for (int j = 0; j < next_size; j++) {
                    if (mapping[words[i][j]] > mapping[words[i + 1][j]])
                        return false;
                    else if (mapping[words[i][j]] == mapping[words[i + 1][j]]) {
                        if (j == next_size - 1)
                            pass_count++;
                        continue;
                    } else {
                        pass_count++;
                        break;
                    }
                }
            }
        }
        if (pass_count == words_size)
            return true;
        else
            return false;
    }
};

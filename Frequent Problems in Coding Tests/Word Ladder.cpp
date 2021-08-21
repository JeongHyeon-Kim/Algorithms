// problem source: https://leetcode.com/problems/word-ladder/
// discussion reference: https://leetcode.com/problems/word-ladder/discuss/1383702/Easy-BFS-approach-in-C%2B%2B
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(), wordList.end());
        queue<string> data;
        int step = 1; // begin and end word's diff is one character at least
        if (dict.find(endWord) == dict.end()) // not found
            return 0;
        data.push(beginWord);
        while (!data.empty()) {
            int data_size = data.size();
            while (data_size) {
                string node = data.front();
                data.pop();
                if (node == endWord)
                    return step;
                for (int i = 0; i < node.length(); i++) {
                    for (char search = 'a'; search <= 'z'; search++) {
                        char target = node[i];
                        node[i] = search;
                        if (dict.find(node) != dict.end()) { // found
                            dict.erase(node);
                            data.push(node);
                        }
                        node[i] = target;
                    }
                }
                data_size--;
            }
            step++;
        }
        return 0;
    }
};

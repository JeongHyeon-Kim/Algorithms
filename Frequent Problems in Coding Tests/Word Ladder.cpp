// problem source: https://leetcode.com/problems/word-ladder/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int word_list_size = wordList.size();
        cout << beginWord << endl;
        cout << endWord << endl;
        for (int i = 0; i < word_list_size; i++)
            cout << wordList[i] << " ";
        return 0;
    }
};

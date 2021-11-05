// problem source: https://leetcode.com/problems/implement-strstr/submissions/
class Solution {
public:
    int strStr(string haystack, string needle) {
        // Short Code
        int index = haystack.find(needle);
        return index == string::npos ? -1 : index;

        // Use If Condition
        int index = haystack.find(needle);
        if (string::npos == index)
            index = -1;
        return index;

        // Initial Code
        // cout << haystack << endl;
        // cout << needle << endl;

        // Take 1 - Use Iteration
        // int haystack_length = haystack.length();
        // int needle_length = needle.length();
        // for (int i = 0; i < haystack_length; i++) {
        //     int count++;
        //     for (int j = 0; j < needle.length(); j++) {
        //         if (haystack[i] == needle[j])
        //             count++;
        //     }
        // }

    }
};

// problem source: https://leetcode.com/problems/group-anagrams/
// discussion reference: https://leetcode.com/problems/group-anagrams/discuss/1325378/C%2B%2B-oror-Hash-Table-oror-Easy-To-Understand
class Solution {
public:
    vector<int> getHashValue(string s) {
        vector<int> hash(26, 0); // alphabet count vector
        for(int i = 0; i < s.size(); i++)
            hash[s[i] - 'a']++;
        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mapping;
        vector<vector<string>> result;
        for (auto str : strs) {
            vector<int> hash = getHashValue(str);
            // key is count for string, value is string
            mapping[hash].push_back(str); // delete reduplication by map
        }
        for(auto it : mapping) {
            vector<string> each_string = it.second;
            result.push_back(each_string);
        }
        return result;

        // try 2
        // int strs_size = strs.size();
        // vector<vector<string>> result;
        // vector<string> middle;
        // if (strs == "") {
        //     string res("");
        //     middle.push_back(res);
        //     result.push_back(middle);
        //     return result;
        // }
        // if (middle.empty())
        //     middle.push_back(strs[0]);
        // for (int i = 1; i < strs_size; i++) {
        //     cout << strs[i] << endl;
        //     string comp(strs[i]);
        //     string comp2(middle[0]);
        //     sort(comp.begin(), comp.end());
        //     sort(comp2.begin(), comp2.end());
        //     if (comp == comp2) {
        //         cout << "found! :"  << strs[i] << endl;
        //         middle.push_back(strs[i]);
        //     } else {
        //         result.push_back(middle);
        //         middle.clear();
        //         middle.push_back(strs[i]);
        //         result.push_back(middle);
        //     }
        // }
        //
        // return result;

        // try 1
        // int strs_size = strs.size();
        // vector<vector<string>> result;
        // map<char, int> mapping;
        // for (int i = 0; i < strs_size; i++) {
        //     string str = strs[i];
        //     int str_size = str.size();
        //     for (int j = 0; j < str_size; j++)
        //         mapping[str[j]]++;
        // }
        // for (auto it = mapping.begin(); it != mapping.end(); it++)
        //     cout << it->first << " " << it->second << endl;
        // return result;
    }
};

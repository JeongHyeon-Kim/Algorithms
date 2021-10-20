// problem source: https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    void recursive_solution(vector<string>& result, int opening_count, int closing_count, string sub_result) { // & is called reference, not address
        if (opening_count == 0 && closing_count == 0) {
            result.push_back(sub_result);
            return;
        }

        if (opening_count != 0)
            recursive_solution(result, opening_count - 1, closing_count, sub_result + '(');

        if (closing_count > opening_count)
            recursive_solution(result, opening_count, closing_count - 1, sub_result + ')');
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int opening_count = n;
        int closing_count = n;
        recursive_solution(result, opening_count, closing_count, "");
        return result;
    }
};

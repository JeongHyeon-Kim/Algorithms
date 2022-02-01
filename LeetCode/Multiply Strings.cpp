// problem source: https://leetcode.com/problems/multiply-strings/
/*
comment
// 큰 숫자는 string으로 변환하여 계산
// i + j 해당 자리
// i + j + 1 올림 자리
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int num1_length = num1.length(), num2_length = num2.length();
        string result;
        vector<int> middle_result(num1_length + num2_length, 0);
        int not_used_index = 0;
        if (num1 == "0" || num2 == "0")
            return "0";
        for (int i = num1_length - 1; i >= 0; i--) {
            for (int j = num2_length - 1; j >= 0; j--) {
                middle_result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                middle_result[i + j] += middle_result[i + j + 1] / 10;
                middle_result[i + j + 1] %= 10;
            }
        }
        while (not_used_index < middle_result.size() && middle_result[not_used_index] == 0)
            not_used_index++;
        while (not_used_index < middle_result.size())
            result.push_back(middle_result[not_used_index++] + '0');
        return result;
    }
};

// problem source: https://leetcode.com/problems/add-strings/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int num1_size = num1.size();
        int num2_size = num2.size();
        int carry = 0;
        if (num1_size < num2_size) {
            for (int i = num2_size - 1; i >= 0; i--) {
                int diff = num2_size - num1_size;
                if (i - diff >= 0) {
                    int sum = (num1[i - diff] - 0x30) + (num2[i] - 0x30) + carry;
                    carry = sum / 10;
                    sum = sum % 10;
                    char sum_char = (char)(sum + 0x30);
                    string sum_string;
                    sum_string += sum_char;
                    result.insert(0, sum_string);
                } else {
                    int sum = (num2[i] - 0x30) + carry;
                    carry = sum / 10;
                    sum = sum % 10;
                    char sum_char = (char)(sum + 0x30);
                    string sum_string;
                    sum_string += sum_char;
                    result.insert(0, sum_string);
                }
                if (carry != 0 && i == 0) {
                    char sum_char = (char)(carry + 0x30);
                    string sum_string;
                    sum_string += sum_char;
                    result.insert(0, sum_string);
                }
            }
        } else {
            for (int i = num1_size - 1; i >= 0; i--) {
                int diff = num1_size - num2_size;
                if (i - diff >= 0) {
                    int sum = (num1[i] - 0x30) + (num2[i - diff] - 0x30)  + carry;
                    carry = sum / 10;
                    sum = sum % 10;
                    char sum_char = (char)(sum + 0x30);
                    string sum_string;
                    sum_string += sum_char;
                    result.insert(0, sum_string);
                } else {
                    int sum = (num1[i] - 0x30) + carry;
                    carry = sum / 10;
                    sum = sum % 10;
                    char sum_char = (char)(sum + 0x30);
                    string sum_string;
                    sum_string += sum_char;
                    result.insert(0, sum_string);
                }
                if (carry != 0 && i == 0) {
                    char sum_char = (char)(carry + 0x30);
                    string sum_string;
                    sum_string += sum_char;
                    result.insert(0, sum_string);
                }
            }
        }
        return result;
    }
};

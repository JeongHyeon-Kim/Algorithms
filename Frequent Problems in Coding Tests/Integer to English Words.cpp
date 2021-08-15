// problem source: https://leetcode.com/problems/integer-to-english-words/
class Solution {
public:
    string numberToWords(int num) {
        string one_unit[10] = {" ", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string under_twenty_unit[10] = {" ", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string ten_unit[10] = {" ", "Ten", "Twenty", "Thirty", "Forty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string bigger_unit[4] = {"Hundred", "Thousand", "Million", "Billion"};
        string result;
        int rotation = 0;
        int bigger_index = 0;
        while (num != 0) { // 123 -> 12 -> 1 -> 0 end
            int number_index = num % 10; // 3 -> 2 -> 1
            num = num / 10;
            if (rotation % 4 == 0) {
                result.insert(0, one_unit[number_index]);
                rotation++;
                if (num != 0)
                    result.insert(0, " ");
            } else if (rotation % 4 == 1) {
                result.insert(0, ten_unit[number_index]);
                rotation++;
                if (num != 0)
                    result.insert(0, " ");
            } else if (rotation % 4 == 2) {
                result.insert(0, bigger_unit[bigger_index % 4]);
                result.insert(0, " ");
                result.insert(0, one_unit[number_index]);
                bigger_index++;
                rotation++;
                if (num != 0)
                    result.insert(0, " ");
            } else { // rotation % 4 == 3
                result.insert(0, bigger_unit[bigger_index % 4]);
                result.insert(0, " ");
                result.insert(0, one_unit[number_index]);
                bigger_index++;
                rotation++;
                if (num != 0)
                    result.insert(0, " ");
            }
        }
        return result;
    }
};

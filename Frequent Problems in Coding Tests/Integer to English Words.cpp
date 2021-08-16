// problem source: https://leetcode.com/problems/integer-to-english-words/
// discussion reference: https://leetcode.com/problems/integer-to-english-words/discuss/1327159/C%2B%2B-clean-recursive-code
class Solution {
public:
    string one_unit[10] = {" ", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    string under_twenty_unit[10] = {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    string ten_unit[10] = {" ", " ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

    string recursive_conversion(int num) {
        if (num >= 1000000000)
            return recursive_conversion(num / 1000000000) + "Billion " + recursive_conversion(num % 1000000000);
        if (num >= 1000000)
            return recursive_conversion(num / 1000000) + "Million " + recursive_conversion(num % 1000000);
        if (num >= 1000)
            return recursive_conversion(num / 1000) + "Thousand " + recursive_conversion(num % 1000);
        if (num >= 100)
            return recursive_conversion(num / 100) + "Hundred " + recursive_conversion(num % 100);
        if (num >= 20) {
            int tens =  num / 10;
            return tens[ten_unit] + recursive_conversion(num % 10);
        }
        if (num >= 10 && num < 20)
            return under_twenty_unit[num % 10];
        if (num < 10)
            return one_unit[num % 10];
        return "";
    }

    string numberToWords(int num) {
        if (num  == 0)
            return "Zero";
        string result, individual_word;
        stringstream extract;
        extract.str(recursive_conversion(num)); // set string
        while (extract >> individual_word) // extract same type of string
            result += individual_word + " ";
        result.pop_back(); // remove last blank
        return result;
    }
};

// problem source: https://leetcode.com/problems/count-and-say/
// discussion reference: https://leetcode.com/problems/count-and-say/discuss/16043/C++-solution-easy-understand
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        while (--n) { // first skip
            string convert = "";
            for (int i = 0; i < result.length(); i++) { // "1"
                int count = 1;
                while ((i + 1 < result.length()) && (result[i] == result[i + 1])) { // last unexpected value, filtered by for condition
                    count++;
                    i++;
                }
                convert += to_string(count) + result[i]; // count and say
            }
            result = convert;
        }
        return result;

        // count and number
        // All PASS Presented Test Case, Wrong With 6
        // if (n == 1)
        //     return "1";
        // else { // n > 1
        //     string result;
        //     string convert = "11"; // n == 2
        //     if (n == 2)
        //         return convert;
        //     else { // n > 2
        //         int iteration = 2;
        //         while (iteration < n) {
        //             int count = 1;
        //             result.clear();
        //             cout << convert << endl;
        //             for (int i = 1; i < convert.length(); i++) { // "1"
        //                 if (convert[i - 1] == convert[i]) {
        //                     count++;
        //                 } else {
        //                     result += to_string(count);
        //                     result += convert[i - 1];
        //                 }
        //                 if (i == convert.length() - 1) { // last location
        //                     result += to_string(count);
        //                     result += convert[i];
        //                 }
        //             }
        //             iteration++;
        //             convert = result;
        //         }
        //     }
        //     return result;
        // }
    }
};

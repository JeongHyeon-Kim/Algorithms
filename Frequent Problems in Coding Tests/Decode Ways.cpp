// problem source: https://leetcode.com/problems/decode-ways/
// discussion reference: https://leetcode.com/problems/decode-ways/discuss/1496665/C++-DP-Solution-100-Faster
class Solution {
public:
    int numDecodings(string s) {
        int s_length = s.length();
        if (s[0] == '0')
            return 0;
        int current = 1;
        int previous = 1;
        for (int i = 1; i < s_length; i++) { // using fibonacci
            int units = s[i] - '0'; // " - '0' " operation is converting string to integer process (units)
            int tens = (s[i - 1] - '0') * 10 + units; // (tens)
            int processing_current = 0;

            if (units > 0 && units < 10)
                processing_current += current;
            if (tens > 9 && tens < 27)
                processing_current += previous;

            previous = current;
            current = processing_current;
        }
        return current;

        // Thinking Process
        // 1 ~ 26 (A ~ Z)
        // 경우의 수 3 -> 1 1 1, 1 2, 2 1, 범위는 26까지, 한 ~ 두 자리 수
        // 2 2 6 -> 0 1 2
        // 피보나치 수열 개의 경우의 수가 생김 -> 그 중 안되는 케이스를 찾아 제외한다면?
        // 1 ~ 26 (A ~ Z)
        // 3 -> 1 1 1, 1 2, 2 1
        // Fibonacci Sequence & Case Exception - Processing
        // if (stoi(s) == 0)
        //     return 0;
        // int s_length = s.length();
        // int first = 1, second = 2;
        // int count = 0;
        // if (s_length == 1) {
        //     int encoded = stoi(s);
        //     if (encoded > 0 && encoded < 10)
        //         return 1;
        //     else
        //         return 0;
        // } else if (s_length == 2) {
        //     if (s[0] == '0')
        //         return 0;
        //     int encoded = stoi(s);
        //     bool exist = true;
        //     if (encoded > 0 && encoded < 27)
        //         count++;
        //     while (encoded != 0) {
        //         int check = encoded % 10;
        //         if (check < 1 || check > 9) {
        //             exist = false;
        //             break;
        //         }
        //         encoded = encoded / 10;
        //     }
        //     if (exist)
        //         return count + 1;
        //     else
        //         return count;
        // } else { // s_length > 3
        //     return s_length;
        // }

        // Wrong with "226", "12"
        // char alphabet[27] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; // unordererd_map
        // if (stoi(s) == 0)
        //     return 0;
        // int s_length = s.length();
        // int count = 0;
        // for (int i = 0; i < s_length; i++) {
        //     // cout << s[i] << " ";
        //     string temp;
        //     temp = s.substr(i, 1);
        //     // cout << temp << endl;
        //     int decoded = stoi(temp);
        //     if (decoded > 0 && decoded < 27) {
        //         cout << decoded << " ";
        //         count++;
        //     }
        // }
        // return 0;
    }
};

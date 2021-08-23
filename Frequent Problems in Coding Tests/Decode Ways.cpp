// problem source: https://leetcode.com/problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        // 1 ~ 26 (A ~ Z)
        // 3 -> 1 1 1, 1 2, 2 1
        // fibonacci sequence & case exception
        if (stoi(s) == 0)
            return 0;
        int s_length = s.length();
        int first = 1, second = 2;
        int count = 0;
        if (s_length == 1) {
            int encoded = stoi(s);
            if (encoded > 0 && encoded < 10)
                return 1;
            else
                return 0;
        } else if (s_length == 2) {
            if (s[0] == '0')
                return 0;
            int encoded = stoi(s);
            bool exist = true;
            if (encoded > 0 && encoded < 27)
                count++;
            while (encoded != 0) {
                int check = encoded % 10;
                if (check < 1 || check > 9) {
                    exist = false;
                    break;
                }
                encoded = encoded / 10;
            }
            if (exist)
                return count + 1;
            else
                return count;
        } else { // s_length > 3
            return s_length;
        }

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

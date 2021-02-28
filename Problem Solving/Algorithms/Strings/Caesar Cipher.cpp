// problem source: https://www.hackerrank.com/challenges/caesar-cipher-1/problem
// discussion reference: https://www.hackerrank.com/challenges/caesar-cipher-1/forum/comments/64559
#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    int s_length = s.length();
    for (int i = 0; i < s_length; i++) {
        if (islower(s[i])) {
            if ((s[i] + k) >= 'a' && (s[i] + k) <= 'z')
                s[i] = s[i] + k;
            else
                s[i] = 'a' + (s[i] - 'a' + k) % 26;
        } else if (isupper(s[i])) {
            if ((s[i] + k) >= 'A' && (s[i] + k) <= 'Z')
                s[i] = s[i] + k;
            else
                s[i] = 'A' + (s[i] - 'A' + k) % 26;
        } else
            continue;
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

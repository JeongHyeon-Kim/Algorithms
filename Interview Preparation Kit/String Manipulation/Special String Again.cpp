// problem source: https://www.hackerrank.com/challenges/special-palindrome-again/problem
// discussion reference: https://www.hackerrank.com/challenges/special-palindrome-again/forum/comments/486258
#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    int valid_string[26] = {0, };
    long result = n;
    for (int period = 2; period <= n; period++) {
        for (int i = 0; i + period <= n; i++) {
            bool valid = true;
            string sub = s.substr(i, period);
            for (int j = 1; j < period; j++) {
                if (period % 2 == 0) {
                    if (sub[0] != sub[j])
                        valid = false;
                } else {
                    if (j != period / 2 && sub[0] != sub[j])
                        valid = false;
                }
            }
            if (valid) result++;
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

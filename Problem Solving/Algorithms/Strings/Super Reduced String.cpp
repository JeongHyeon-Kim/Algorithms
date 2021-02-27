// problem source: https://www.hackerrank.com/challenges/reduced-string/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == s[i]) {
            s = s.substr(0, i - 1) + s.substr(i + 1);
            i = 0;
        }
    }
    if (s.empty())
        return "Empty String";
    else
        return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

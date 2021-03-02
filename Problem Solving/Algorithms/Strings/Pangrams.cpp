// problem source: https://www.hackerrank.com/challenges/pangrams/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    int alpha[26] = {0, };
    for (char i : s) {
        if (isupper(i))
            i = tolower(i);
        alpha[i - 'a']++;
    }
    for (int i : alpha) {
        if (i)
            continue;
        else
            return "not pangram";
    }
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

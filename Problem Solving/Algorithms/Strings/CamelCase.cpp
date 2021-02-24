// problem source: https://www.hackerrank.com/challenges/camelcase/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {
    int s_size = s.size();
    int word_count = 0;
    for (int i = 0; i < s_size; i++) {
        if (isupper(s[i]))
            word_count++;
    }
    return word_count + 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

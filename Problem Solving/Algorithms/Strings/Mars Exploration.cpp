// problem source: https://www.hackerrank.com/challenges/mars-exploration/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {
    int s_size = s.size();
    int sos_count = s_size / 3;
    int diff = 0;
    for (int i = 0; i < sos_count; i++) {
        if (s[i * 3] != 'S')
            diff++;
        if (s[i * 3 + 1] != 'O')
            diff++;
        if (s[i * 3 + 2] != 'S')
            diff++;
    }
    return diff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

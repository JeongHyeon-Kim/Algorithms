// problem source: https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    string hackerrank = "hackerrank";
    int index = 0;
    for (char i : s) {
        if (i == hackerrank[index])
            index++;
        if (hackerrank[index] == '\0')
            return "YES";
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

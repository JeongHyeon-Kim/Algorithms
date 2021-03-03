// problem source: https://www.hackerrank.com/challenges/funny-string/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
    vector<int> forward_diff;
    vector<int> reverse_diff;
    for (auto i = s.begin() + 1; i != s.end(); i++)
        forward_diff.push_back(abs(*i - *(i - 1)));
    for (auto i = s.rbegin() + 1; i != s.rend(); i++)
        reverse_diff.push_back(abs(*i - *(i - 1)));
    for (int i = 0; i < forward_diff.size(); i++) {
        if (forward_diff[i] != reverse_diff[i])
            return "Not Funny";
    }
    return "Funny";
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

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

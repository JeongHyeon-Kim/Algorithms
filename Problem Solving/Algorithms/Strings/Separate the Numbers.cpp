// problem source: https://www.hackerrank.com/challenges/separate-the-numbers/problem
// discussion reference: https://www.hackerrank.com/challenges/separate-the-numbers/forum/comments/300829
#include <bits/stdc++.h>

using namespace std;

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    int s_size = s.size();
    string sub, start_sub;
    for(int i = 1; i <= s_size / 2 && s != sub; i++) { // make sub to s by loop
        start_sub = sub = s.substr(0, i);
        for(int i = 1; sub.size() < s_size; i++)
            sub += to_string(stoll(start_sub) + i);
    }
    cout << (s == sub ? "YES " + start_sub : "NO") << endl;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}

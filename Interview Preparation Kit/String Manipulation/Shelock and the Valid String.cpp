// problem source: https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
// discussion reference: https://numgos.tistory.com/38, https://chickenpaella.tistory.com/87
#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int s_size = s.size();
    int char_count[26] = {0, };
    int check = 0;
    int max = INT_MIN;
    vector<int> counting;
    for (int i = 0; i < s_size; i++)
        char_count[s[i] - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (char_count[i] > 0)
            counting.push_back(char_count[i]);
    }
    sort(counting.begin(), counting.end());
    int counting_size = counting.size();
    bool once = false;
    for (int i = 1; i < counting_size; i++) {
        if (counting[i - 1] == counting[i])
            continue;
        else {
            if (once)
                return "NO"; // ex) 1 2 2 3
            if (i - 1 == 0 && !once) {
                once = true; // ex) 1 2 2 2
                continue;
            }
            if ( (i != counting_size - 1) || (counting[i] - counting[i - 1] != 1) )
                return "NO"; // ex1) 1 1 2 2, ex2) 1 1 1 3

        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

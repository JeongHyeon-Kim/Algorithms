// https://www.hackerrank.com/challenges/ctci-making-anagrams/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int first_string[26] = {0, };
    int second_string[26] = {0, };
    int a_size = a.size();
    int b_size = b.size();
    int total =  0;

    for (int i = 0; i < a_size; i++) {
        int alpha_order = a[i] - 'a';
        first_string[alpha_order]++;
    }
    for (int i = 0; i < b_size; i++) {
        int alpha_order = b[i] - 'a';
        second_string[alpha_order]++;
    }
    for (int i = 0; i < 26; i++) {
        total += abs(first_string[i] - second_string[i]);
    }
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

// problem source: https://www.hackerrank.com/challenges/two-strings/problem
// discussion reference: http://jinyongjeong.github.io/2020/06/29/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Map-and-Unordered_map/, https://stackoverrun.com/ko/q/1040699
#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    // Did not execute within the time limits
    // int s1_size = s1.size();
    // int s2_size = s2.size();
    // for (int i = 0; i < s1_size; i++) {
    //     for (int j = 0; j < s2_size; j++){
    //         if (s1[i] == s2[j])
    //             return "YES";
    //     }
    // }
    // return "NO";
    int s1_size = s1.size();
    int s2_size = s2.size();
    unordered_map<char, int> hashed;
    for (int i = 0; i < s1_size; i++) {
        hashed[s1[i]];
    }
    for (int i = 0; i < s2_size; i++) {
        if (hashed.find(s2[i]) != hashed.end())
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
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

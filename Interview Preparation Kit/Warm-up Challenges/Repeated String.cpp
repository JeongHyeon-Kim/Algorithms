// problem source: https://www.hackerrank.com/challenges/repeated-string/problem
// discussion reference: https://www.hackerrank.com/challenges/repeated-string/forum/comments/217173
#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long count = 0;
    long repeated = n / s.size();

    // Did not execute within the time limits
    // string s_edited;
    // if (repeated >= 1) {
    //     for (int i = 0; i < repeated; i++)
    //         s_edited.append(s);
    //     long remain_size = n - repeated * s.size();
    //     string remain_string = s.substr(0, remain_size);
    //     s_edited.append(remain_string);
    // } else {
    //     string remain_string = s.substr(0, n);
    //     s_edited.append(remain_string);
    // }

    long remain_size = n - repeated * s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a')
            count++;
    }
    count *= repeated;
    for (int i = 0; i < remain_size; i++){
        if (s[i] == 'a')
            count++;
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

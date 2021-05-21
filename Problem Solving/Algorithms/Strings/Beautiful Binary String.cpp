// problem source: https://www.hackerrank.com/challenges/beautiful-binary-string/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'beautifulBinaryString' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING b as parameter.
 */

int beautifulBinaryString(string b) {
    int b_size = b.size();
    string sub = "010";
    int count = 0;
    bool found = true;
    while (found) {
        found = false;
        for (int i = 0; i < b_size - 2; i++) {
            if (b[i] == '0' && b[i + 1] == '1' && b[i + 2] == '0') {
                found = true;
                if (b[i + 3] == '0') {
                    b[i + 1] = '0';
                    count++;
                } else if (b[i + 3] == '1') {
                    b[i + 2] = '1';
                    count++;
                } else { // b[i + 3] == '\0' is end of string
                    b[i + 1] = '0';
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

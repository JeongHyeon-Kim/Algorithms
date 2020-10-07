// problem source: https://www.hackerrank.com/challenges/counting-valleys/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int sea_level = 0;
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (sea_level == 0 && s[i] == 'D' ) {
            result++;
            // cout << "result : " << result << endl;
        }
        if (s[i] == 'U') {
            sea_level += 1;
            // cout << sea_level << endl;
        } else { // D
            sea_level -= 1;
            // cout << sea_level << endl;
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

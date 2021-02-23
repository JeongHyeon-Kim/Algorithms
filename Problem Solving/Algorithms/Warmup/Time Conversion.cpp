// problem source: https://www.hackerrank.com/challenges/time-conversion/problem
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    string result;
    if (s.substr(8, 2) == "PM") {
        if (stoi(s.substr(0, 2)) < 12) {
            int convert_time = stoi(s.substr(0, 2)) + 12;
            result = to_string(convert_time) + s.substr(2, 6);
        } else // 12:xx:xxPM
            result = s.substr(0, 8);
    } else { // AM
        if (stoi(s.substr(0, 2)) < 12)
            result = s.substr(0, 8);
        else // 12:xx:xxAM
            result = "00" + s.substr(2, 6);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

// problem source: https://www.hackerrank.com/challenges/strong-password/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    bool checking[4] = {false, };
    int count = 0;

    for (char i : numbers) {
        if (password.find(i) != string::npos) {
            checking[0] = true;
            break;
        }
    }

    for (char i : lower_case) {
        if (password.find(i) != string::npos) {
            checking[1] = true;
            break;
        }
    }

    for (char i : upper_case) {
        if (password.find(i) != string::npos) {
            checking[2] = true;
            break;
        }
    }

    for (char i : special_characters) {
        if (password.find(i) != string::npos) {
            checking[3] = true;
            break;
        }
    }

    for (bool i : checking) {
        if (i == false)
            count++;
    }

    if (n < 6) {
        if (6 - n > count)
            count = 6 - n;
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

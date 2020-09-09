// problem source: https://www.hackerrank.com/challenges/30-data-types/problem

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";


    // Declare second integer, double, and String variables.
    int s_i;
    double s_d;
    string s_s;

    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    cin >> s_i;
    cin >> s_d;
    getline(cin >> ws, s_s);

    // Print the sum of both integer variables on a new line.
    cout << i + s_i << endl;
    // Print the sum of the double variables on a new line.
    cout << fixed << setprecision(1) << d + s_d << endl;
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout << s << s_s << endl;


    return 0;
}

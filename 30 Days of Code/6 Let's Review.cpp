// problem source: https://www.hackerrank.com/challenges/30-review-loop/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int test_case;
    cin >> test_case;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < test_case; i++) {
        string input_string, even_string, odd_string;
        cin >> input_string;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int string_index = 0; string_index < input_string.size(); string_index++) {
            if (string_index % 2 == 0)
                even_string += input_string[string_index];
            if (string_index % 2 == 1)
                odd_string += input_string[string_index];
        }
        cout << even_string << " " << odd_string << endl;
    }
    return 0;
}

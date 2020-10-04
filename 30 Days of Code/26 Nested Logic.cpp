// problem source: https://www.hackerrank.com/challenges/30-nested-logic/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int actualDay, actualMonth, actualYear;
    int expectedDay, expectedMonth, expectedYear;
    int fine = 0;
    cin >> actualDay >> actualMonth >> actualYear;
    cin >> expectedDay >> expectedMonth >> expectedYear;
    if (expectedYear < actualYear)
        fine = 10000;
    else if (expectedYear == actualYear) {
        if (expectedMonth < actualMonth)
            fine = (actualMonth - expectedMonth) * 500;
        else if (expectedMonth == actualMonth) {
            if (expectedDay < actualDay) {
                fine = (actualDay - expectedDay) * 15;
            }
        }
    }
    cout << fine << endl;
    return 0;
}

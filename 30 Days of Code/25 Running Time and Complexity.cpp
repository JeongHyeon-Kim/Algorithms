// problem source: https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem
// discussion reference: https://marobiana.tistory.com/91
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, data;
    cin >> T;
    while (T-->0) {
        cin >> data;
        bool isPrime = true;
        for (int i = 2; i <= sqrt(data); i++) { // not forget using sqrt and equal
            if (data % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (data == 1)
            cout << "Not prime" << endl;
        else if (isPrime)
            cout << "Prime" << endl;
        else
            cout << "Not prime" << endl;
    }
    return 0;
}

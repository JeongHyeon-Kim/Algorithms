// problem source: https://www.hackerrank.com/challenges/30-binary-numbers/problem
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int count = 0, max = 0;

    while (n > 0) {
        if (n % 2 == 1) {
            count += 1;
            if (max < count) {
                max = count;
            }
        } else {
            count = 0;
        }
        n = n / 2;
    }

    cout << max;

    return 0;
}

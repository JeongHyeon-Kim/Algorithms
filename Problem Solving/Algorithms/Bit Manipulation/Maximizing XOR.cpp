// problem source: https://www.hackerrank.com/challenges/maximizing-xor/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the maximizingXor function below.
int maximizingXor(int l, int r) {
    int max_xor = 0;
    for (int i = l; i <= r; i++) {
        for (int j = l; j <= r; j++) {
            if (max_xor < (i ^ j))
                max_xor = i ^ j;
        }
    }
    return max_xor;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int l;
    cin >> l;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int r;
    cin >> r;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = maximizingXor(l, r);

    fout << result << "\n";

    fout.close();

    return 0;
}

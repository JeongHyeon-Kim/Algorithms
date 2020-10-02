<<<<<<< HEAD
=======
// problem source: https://www.hackerrank.com/challenges/30-2d-arrays/problem
>>>>>>> d67014e29801fa72c59427e9a846d36f44a9fefb
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}

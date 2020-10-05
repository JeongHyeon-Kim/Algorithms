// problem source: https://www.hackerrank.com/challenges/30-2d-arrays/problem
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> arr(6);
    int max = INT_MIN; // minimum value of int
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int search_i = 0; search_i < 4; search_i++) {
        for (int search_j = 0; search_j < 4; search_j++) {
            sum = 0;
            sum = arr[search_i][search_j] + arr[search_i][search_j + 1] + arr[search_i][search_j + 2];
            sum += arr[search_i + 1][search_j + 1];
            sum += arr[search_i + 2][search_j] + arr[search_i + 2][search_j + 1] + arr[search_i + 2][search_j + 2];
            if (max < sum)
                max = sum;
        }
    }
    cout << max << endl;
    return 0;
}

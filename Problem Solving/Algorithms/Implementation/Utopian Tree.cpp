// problem source: https://www.hackerrank.com/challenges/utopian-tree/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the utopianTree function below.
int utopianTree(int n) {
    int result_height = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1)
            result_height = result_height + 1;
        else
            result_height = result_height * 2;
    }
    return result_height;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = utopianTree(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

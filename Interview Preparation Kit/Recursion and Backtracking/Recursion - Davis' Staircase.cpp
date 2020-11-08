// problem source: https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem
// discussion reference: https://www.hackerrank.com/challenges/ctci-recursive-staircase/forum/comments/859768, https://www.hackerrank.com/challenges/ctci-recursive-staircase/forum/comments/227816
#include <bits/stdc++.h>

using namespace std;

// Complete the stepPerms function below.
int stepPerms(int n) {
    // Code did not execute within the time limits
    // if (n == 1)
    //     return 1;
    // else if (n == 2)
    //     return 2;
    // else if (n == 3)
    //     return 4;
    // else
    //   return stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3);
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (n == 3) {
        return 4;
    } else {
        vector<int> summing(3);
        summing[0] = 1;
        summing[1] = 2;
        summing[2] = 4;
        for (int i = 3; i < n; i++) {
            summing.push_back(summing[i - 1] + summing[i - 2] + summing[i - 3]);
        }
        return summing[n - 1];
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}

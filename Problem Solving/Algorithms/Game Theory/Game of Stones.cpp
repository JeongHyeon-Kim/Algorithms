// problem source: https://www.hackerrank.com/challenges/game-of-stones-1/problem
// discussion reference: https://www.hackerrank.com/challenges/game-of-stones-1/forum/comments/140085
#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfStones function below.
string gameOfStones(int n) {
    return (n % 7 == 0 || n % 7 == 1) ? "Second" : "First";
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

        string result = gameOfStones(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

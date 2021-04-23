// problem source: https://www.hackerrank.com/challenges/strange-advertising/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int init = 5;
    int cumulative = 0;
    for (int i = 0; i < n; i++) {
        int liked = init / 2;
        init = liked * 3;
        cumulative += liked;
    }
    return cumulative;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

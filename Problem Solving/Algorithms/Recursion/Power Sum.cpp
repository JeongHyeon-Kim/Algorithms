// problem source: https://www.hackerrank.com/challenges/the-power-sum/problem
// discussion reference: https://www.hackerrank.com/challenges/the-power-sum/forum/comments/296625
#include <bits/stdc++.h>

using namespace std;

int findPowerSum(int total, int power, int num) {
    int value = static_cast<int>(total - pow(num, power)); // number and power

    if(value < 0) return 0;
    else if(value == 0) return 1;
    else return findPowerSum(value, power, num + 1) +
                findPowerSum(total, power, num + 1);
}

// Complete the powerSum function below.
int powerSum(int X, int N) {
    return findPowerSum(X, N, 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}

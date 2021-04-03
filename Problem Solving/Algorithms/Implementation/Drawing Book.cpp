// problem source: https://www.hackerrank.com/challenges/drawing-book/problem
// discussion reference: https://www.hackerrank.com/challenges/drawing-book/forum/comments/266866
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    /*
     * Write your code here.
     */
    // 2/26 test cases failed
    // float result = 0;
    // if (p - 1 > n - p)
    //     result = floor(float((n - p) / 2.0));
    // else if (p - 1 < n - p)
    //     result = ceil(float((p - 1) / 2.0));
    // else { // p - 1 == n - p
    //     result = ceil(float((p - 1) / 2.0));
    // }
    // return (int)result;

    return min(p/2, n/2 - p/2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}

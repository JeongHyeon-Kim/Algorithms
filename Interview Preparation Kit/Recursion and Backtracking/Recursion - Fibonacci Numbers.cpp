// problem source: https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem
// discussion reference: https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/forum/comments/210194
#include <iostream>

using namespace std;

int fibonacci(int n) {
    // Complete the function.
    // original code
    // if (n == 0)
    //     return 0;
    // else if (n == 1)
    //     return 1;
    // else
    //     return fibonacci(n - 2) + fibonacci(n - 1);
    if (n < 2)
        return n;
    else
        return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}

// problem source: https://www.hackerrank.com/challenges/maximum-element/problem
// discussion reference: https://www.hackerrank.com/challenges/maximum-element/forum/comments/127390
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // vector<int> data;
    // int test_cases;
    // cin >> test_cases;
    // for (int i = 0; i < test_cases; i++) {
    //     int query;
    //     cin >> query;
    //     if (query == 1) {
    //         int insert;
    //         cin >> insert;
    //         data.push_back(max(insert, data.back()));
    //     } else if (query == 2) {
    //         data.pop_back();
    //     } else { // query == 3
    //         // Terminated due to timeout
    //         int max = 0;
    //         for (auto it = data.begin(); it != data.end(); it++) {
    //             if (max < *it)
    //                 max = *it;
    //         }
    //         cout << max << endl;

    //         // Terminated due to timeout
    //         cout << *max_element(data.begin(), data.end()) << endl;
    //     }

    // }
    stack<int> data;
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            int insert;
            cin >> insert;
            if (data.empty())
                data.push(insert);
            else
                data.push(max(insert, data.top()));
        } else if (query == 2)
            data.pop();
        else // query == 3
            cout << data.top() << endl;
    }
    return 0;
}

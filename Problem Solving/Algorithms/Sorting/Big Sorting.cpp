// problem source: https://www.hackerrank.com/challenges/big-sorting/problem
// discussion reference: https://www.hackerrank.com/challenges/big-sorting/forum/comments/301819
#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b)
{
    int a_size = a.length();
    int b_size = b.length();
    if(a_size == b_size)
        return a < b;

    return a_size < b_size;
}

// Complete the bigSorting function below.
vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), comp);
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

// python reference code:https://www.hackerrank.com/challenges/big-sorting/forum/comments/326995
/*
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the bigSorting function below.
def bigSorting(unsorted):
    sorted_string = []
    for s in sorted(unsorted, key=int):
        sorted_string.append(s);
    return sorted_string
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    unsorted = []

    for _ in range(n):
        unsorted_item = input()
        unsorted.append(unsorted_item)

    result = bigSorting(unsorted)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
*/

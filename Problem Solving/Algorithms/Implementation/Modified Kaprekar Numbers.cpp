// problem source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem
// discussion reference: https://www.hackerrank.com/challenges/kaprekar-numbers/forum/comments/447953
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q) {
    vector<long long> result;
    for (long long i = p; i <= q; i++) {
        int left, right;
        long long square = i * i;
        int len = (int)log10(i) + 1;
        left = square / (int)pow(10, len);
        right = square % (int)pow(10, len);
        if (left + right == i)
            result.push_back(i);
    }
    int result_size = result.size();
    if (result.empty())
        cout << "INVALID RANGE";
    else {
        for (int i = 0; i < result_size; i++)
            cout << result[i] << " ";
    }
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

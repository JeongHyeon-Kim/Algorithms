// problem source: https://www.hackerrank.com/challenges/recursive-digit-sum/problem
// discussion reference: https://www.hackerrank.com/challenges/recursive-digit-sum/forum/comments/736711
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int makingSuperDigit(long long int P) {
    if (P < 10)
        return P;
    long long int sum = 0;
    long long int processed = 0;
    while(P != 0) {
        processed = P % 10;
        sum += processed;
        P = P / 10;
    }
    return makingSuperDigit(sum);
}

// Complete the superDigit function below.
int superDigit(string n, int k) {
    // Abort Called at 7, 8, 9 Case
    // string k_times_n;
    // for (long long int i = 0; i < k; i++)
    //     k_times_n.append(n);
    // while (true) {
    //     long long int n_size = k_times_n.size();
    //     if (n_size == 1)
    //         return stoi(k_times_n);
    //     long long int sum = 0;
    //     for (long long int i = 0; i < n_size; i++)
    //         sum += k_times_n[i] - 48;
    //     k_times_n = to_string(sum);
    // }
    int n_size = n.size();
    long long int sum = 0;
    for (int i = 0; i < n_size; i++)
        sum += n[i] - 48;
    long long int P = sum * k;
    return makingSuperDigit(P);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    string n = nk[0];

    int k = stoi(nk[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

// problem source: https://www.hackerrank.com/challenges/greedy-florist/problem
// discussion reference: https://www.hackerrank.com/challenges/greedy-florist/forum/comments/358393
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
    // 5/12 test cases failed
    // int c_size = c.size();
    // int minimum = 0;
    // sort(c.begin(), c.end(), greater<int>());
    // for (int i = 0; i < k; i++) {
    //     minimum += c[i];
    // }
    // cout << minimum << endl;
    // for (int i = k; i < c_size; i++) {
    //     minimum += 2 * c[i];
    // }
    // return minimum;

    int minimum = 0;
    int c_size = c.size();
    sort(c.begin(), c.end(), greater<int>());
    for(int i = 0; i < c_size; i++) {
        minimum += ((i / k) + 1) * c[i]; // When the number of flowers is n times more than the friend, the weight increases from 1 to n.
    }
    return minimum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int minimumCost = getMinimumCost(k, c);

    fout << minimumCost << "\n";

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

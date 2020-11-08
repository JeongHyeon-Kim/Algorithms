// problem source: https://www.hackerrank.com/challenges/crush/problem
// discussion reference: https://www.hackerrank.com/challenges/crush/forum/comments/69550
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    // Did not execute within the time limits
    // long max = 0;
    // int test_case = queries.size();
    // vector<long> updating_arr(n);
    // int start, end, min_start = 0, max_end = 0;
    // for (int i = 0; i < test_case; i++) {
    //     start = queries[i][0] - 1;
    //     end = queries[i][1];
    //     if (min_start > start)
    //         min_start = start;
    //     if (max_end < end)
    //         max_end = end;
    //     for (int j = start; j < end; j++)
    //         updating_arr[j] += queries[i][2];
    //
    // }
    // summing method 1
    // for (int i = min_start; i < max_end; i++) {
    //     if (max < updating_arr[i])
    //         max = updating_arr[i];
    // }
    // return max;
    // summing method 2
    // vector<long>::iterator max_pos;
    // max_pos = max_element(updating_arr.begin(), updating_arr.end());
    // int get_diff = std::distance(updating_arr.begin(), max_pos);
    // return updating_arr[get_diff];
    long max = 0, comp = 0;
    int test_case = queries.size();
    vector<long> updating_arr(n + 1); // not using index 0 of updating_arr

    for (int i = 0; i < test_case; i++) {
        int start = queries[i][0];
        int end = queries[i][1];
        int value = queries[i][2];

        updating_arr[start] += value; // start point of including
        if ((end + 1) <= n)
            updating_arr[end + 1] -= value; // end point of not including
    }
    for (int i = 1; i <= n; i++) {
        cout << updating_arr[i] << " ";
        comp += updating_arr[i];
        if (max < comp)
            max = comp;
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

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

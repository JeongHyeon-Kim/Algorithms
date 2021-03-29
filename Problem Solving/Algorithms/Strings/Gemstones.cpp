// problem source: https://www.hackerrank.com/challenges/gem-stones/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    int arr_size = arr.size();
    unordered_map<char, int> mapping[arr_size]; // char and count
    int count = 0;
    vector<vector<bool>> exist(arr_size, vector<bool>(26, false));
    bool result[26];
    fill_n(result, 26, true);
    for (int i = 0; i < arr_size; i++) {
        int string_size = arr[i].size();
        string individual_string = arr[i];
        for (int j = 0; j < string_size; j++)
            mapping[i][individual_string[j]]++;
    }
    for (int i = 0; i < arr_size; i++) {
        for (auto it = mapping[i].begin(); it != mapping[i].end(); it++) {
            char individual_char = it->first;
            exist[i][individual_char - 97] = true;
        }
    }
    for (int i = 0; i < arr_size; i++) {
        for (int j = 0; j < 26; j++) {
            if (!exist[i][j])
                result[j] = false;
        }
    }
    for (int i = 0; i < 26; i++) {
        if(result[i])
            count++;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

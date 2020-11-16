// problem source: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int ex_size = expenditure.size();
    // priority_queue<int, vector<int>, greater<int>> trailing_data;
    vector<int> trailing_data;
    int notification = 0;
    cout << ex_size << endl;
    for (int i = 0; i < ex_size; i++) {
        // cout << expenditure[i] << " ";
        if (i < d) {
            trailing_data.push_back(expenditure[i]);
        }
        if (trailing_data.size() == d) {
            sort(trailing_data.begin(), trailing_data.end(), less<int>());
            for (auto it = trailing_data.begin(); it != trailing_data.end(); it++)
                cout << *it << " ";
            cout << endl;
            // if (d % 2 == 1) {
            //     cout << trailing_data[d % 2] << endl;
            //     if (trailing_data[d % 2] * 2 <= expenditure[i])
            //         notification++;
            // } else {
            //     double temp = trailing_data[d % 2 - 1] + trailing_data[d % 2];
            //     cout << temp / 2 << endl;
            //     if (temp <= expenditure[i]) {
            //         notification++;
            //     }
            // }
            // // cout << trailing_data.top() << " ";
            trailing_data.erase(trailing_data.begin());
            trailing_data.push_back(expenditure[i]);
        }
    }
    // sort(trailing_data.begin())
    return notification;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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

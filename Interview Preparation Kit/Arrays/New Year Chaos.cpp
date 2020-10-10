// problem source: https://www.hackerrank.com/challenges/new-year-chaos/problem
// discussion reference: https://www.hackerrank.com/challenges/new-year-chaos/forum/comments/143969
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    // Passsing only one case
    // vector<int> comp_q(q.size());
    // int total_count = 0;
    // for (int i = 0; i < comp_q.size(); i++)
    //     comp_q[i] = i + 1;
    // for (int i = q.size() - 1; i > 0; i--) { // higher than 1
    //     int count = 0;
    //     while (count <= 2) {
    //         if (q[i] == comp_q[i])
    //             break;
    //         else {
    //             int tmp = comp_q[i-1];
    //             comp_q[i-1] = comp_q[i];
    //             comp_q[i] = tmp;
    //             count++;
    //         }
    //     }
    //     if (count > 2) {
    //         cout << "Too chaotic" << endl;
    //         return;
    //     }
    //     else
    //         total_count += count;
    // }
    // cout << total_count << endl;

    int count = 0;
    for (int i = q.size() - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            // Calculate the difference (must be less than or equal to 2)
            // between the elements of the array (q[i])
            // and the corresponding position (i+1) to the actual position
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = q[i] - 2; j < i; j++) {
            // Repeats from the maximum forward point (q[i]-2)
            // to the position of the current array (i)
            if (q[j] > q[i])
                count++;
        }
    }
    cout << count << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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

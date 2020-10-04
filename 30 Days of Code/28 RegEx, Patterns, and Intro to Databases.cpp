// problem source: https://www.hackerrank.com/challenges/30-regex-patterns/problem
// discussion reference: https://blankspace-dev.tistory.com/314, https://blockdmask.tistory.com/178, Regular Expression/implement.cpp
#include <bits/stdc++.h>
#include <regex>

using namespace std;

vector<string> split_string(string);

int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> names;

    for (int N_itr = 0; N_itr < N; N_itr++) {
        string firstNameEmailID_temp;
        getline(cin, firstNameEmailID_temp);

        vector<string> firstNameEmailID = split_string(firstNameEmailID_temp);

        string firstName = firstNameEmailID[0];

        string emailID = firstNameEmailID[1];

        regex reg("[^(a-z)]"); // validation of firstName
        string editedName = regex_replace(firstName, reg, "");
        if (editedName.size() != 0) {
            regex reg("[^(a-z@.)]"); // validation of emailID
            string editedEmail = regex_replace(emailID, reg, "");
            if (editedEmail.size() != 0) {
                if (editedEmail.find("@gmail.com") != string::npos) // validation of gmail user
                    names.push_back(editedName);
            }
        }
    }
    sort(names.begin(), names.end());
    for (int i = 0; i < names.size(); i++)
       cout << names[i] << endl;
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

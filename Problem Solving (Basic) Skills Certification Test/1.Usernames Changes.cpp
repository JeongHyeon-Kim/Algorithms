// problem reference: https://www.hackerrank.com/skills-verification/problem_solving_basic
#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'possibleChanges' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY usernames as parameter.
 */

vector<string> possibleChanges(vector<string> usernames) {
    // Passwd 6/14 test cases
    vector<string> result;
    int u_count = usernames.size();
    int char_count[26] = {0, };
    bool found = false;
    vector<int> comp;
    for (int i = 0; i < u_count; i ++) {
        int c_size = usernames[i].size();
        string temp = usernames[i];
        for (int j = 0; j < c_size; j++)
            comp.push_back(temp[j] - 'a');
        // for (int j = 0; j < c_size; j++)
        //     cout << comp[j] << " ";
        // cout << endl;
        for (int j = 0; j < c_size - 1; j++) {
            // cout << comp[j] << " ";
            for (int k = j + 1; k < c_size; k++) {
                if (comp[j] > comp[k]) {
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        if (found) {
            // result.push_back(usernames[i]);
            result.push_back("YES");
        } else {
            // result.push_back(usernames[i]);
            result.push_back("NO");
        }
        comp.clear();
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string usernames_count_temp;
    getline(cin, usernames_count_temp);

    int usernames_count = stoi(ltrim(rtrim(usernames_count_temp)));

    vector<string> usernames(usernames_count);

    for (int i = 0; i < usernames_count; i++) {
        string usernames_item;
        getline(cin, usernames_item);

        usernames[i] = usernames_item;
    }

    vector<string> result = possibleChanges(usernames);

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

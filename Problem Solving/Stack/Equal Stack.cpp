// problem source: https://www.hackerrank.com/challenges/equal-stacks/problem
// discussion reference: https://www.hackerrank.com/challenges/equal-stacks/forum/comments/912161
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int h1_size = h1.size();
    int h2_size = h2.size();
    int h3_size = h3.size();

    stack<int> s1, s2, s3;
    int h1_height = 0, h2_height = 0, h3_height = 0;
    for (int i = h1_size - 1; i >= 0; i--) {
        s1.push(h1[i]);
        h1_height += h1[i];
    }
    for (int i = h2_size - 1; i >= 0; i--) {
        s2.push(h2[i]);
        h2_height += h2[i];
    }
    for (int i = h3_size - 1; i >= 0; i--) {
        s3.push(h3[i]);
        h3_height += h3[i];
    }
    // while (!s1.empty() && !s2.empty()) {
    //     if (h1_height == h2_height) {
    //         while (!s3.empty()) {
    //             if (h2_height == h3_height)
    //                 return h3_height;
    //             else {
    //                 h3_height -= s3.top();
    //                 s3.pop();
    //             }
    //         }
    //     } else {
    //         if (h1_height > h2_height) {
    //             h1_height -= s1.top();
    //             s1.pop();
    //         } else {
    //             h2_height -= s2.top();
    //             s2.pop();
    //         }
    //     }
    // }
    while (!s1.empty() || !s2.empty() || !s3.empty() ) {
        int minimal_value = min({h1_height, h2_height, h3_height});
        while (h1_height > minimal_value) {
                h1_height -= s1.top();
                s1.pop();
        }
        while (h2_height > minimal_value) {
                h2_height -= s2.top();
                s2.pop();
        }
        while (h3_height > minimal_value) {
                h3_height -= s3.top();
                s3.pop();
        }
        if (h1_height == h2_height && h2_height == h3_height)
            return h3_height;
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

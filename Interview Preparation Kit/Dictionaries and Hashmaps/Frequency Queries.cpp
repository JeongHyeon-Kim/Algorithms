// problem source: https://www.hackerrank.com/challenges/frequency-queries/problem
// discussion reference: https://www.hackerrank.com/challenges/frequency-queries/forum/comments/487790, https://one-step-a-day.tistory.com/88
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    map<int, int> freqMap;
    map<int, int> freqCountMap;
    vector<int> result;
    int q_size = queries.size();
    for (int i = 0; i < q_size; i++) {
        int operation = queries[i][0];
        int element = queries[i][1];
        if (operation == 1) {
            int elem = freqMap[element];
            if(elem > 0) { // not first
                freqCountMap[elem]--; // because of increasing element (updateded count of frequency)
            }
            freqMap[element]++; // incresing frequency and
            freqCountMap[freqMap[element]]++; // refreshing freqCountMap cause by increasing element
        } else if (operation == 2) {
            int temp = freqMap[element];
            if (temp > 0) { // exist element
                freqCountMap[temp]--; // because of decreasing element (updateded count of frequency)
                freqMap[element]--; // decreasing frequency and
                freqCountMap[freqMap[element]]++; // refreshing freqCountMap cause by decreasing element
            }
        } else { // operation == 3
            int res = freqCountMap[element]; // solved time limit condition from searching by map
            if (res > 0)
                result.push_back(1);
            else
                result.push_back(0);
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
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

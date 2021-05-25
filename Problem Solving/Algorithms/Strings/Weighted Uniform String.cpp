// problem source: https://www.hackerrank.com/challenges/weighted-uniform-string/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    //8/32 test cases failed
    vector<string> answer;
    vector<int> weight;
    unordered_map<char, int> mapping;
    for (char i : s)
        mapping[i]++;
    for (auto i : mapping) {
        for (int j = 1; j <= i.second; j++)
            weight.push_back((i.first - 'a' + 1) * j);
    }
    for (int i : queries) {
        if (find(weight.begin(), weight.end(), i) != weight.end())
            answer.push_back("Yes");
        else
            answer.push_back("No");
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

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

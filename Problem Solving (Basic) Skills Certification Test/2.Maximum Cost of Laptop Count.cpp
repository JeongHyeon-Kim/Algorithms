// problem reference: https://www.hackerrank.com/skills-verification/problem_solving_basic
#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maxCost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. STRING_ARRAY labels
 *  3. INTEGER dailyCount
 */

int maxCost(vector<int> cost, vector<string> labels, int dailyCount) {
    // Passed all test cases
    int maxCost = 0;
    int c_count = cost.size();
    int counting = 0;
    int comp = 0;
    for (int i = 0; i < c_count; i++) {
        if (labels[i] == "legal") {
            counting++;
            comp += cost[i];
        } else
            comp += cost[i];
        if (counting == dailyCount) {
            counting = 0;
            if (comp > maxCost)
                maxCost = comp;
            comp = 0;
        }
    }
    return maxCost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string cost_count_temp;
    getline(cin, cost_count_temp);

    int cost_count = stoi(ltrim(rtrim(cost_count_temp)));

    vector<int> cost(cost_count);

    for (int i = 0; i < cost_count; i++) {
        string cost_item_temp;
        getline(cin, cost_item_temp);

        int cost_item = stoi(ltrim(rtrim(cost_item_temp)));

        cost[i] = cost_item;
    }

    string labels_count_temp;
    getline(cin, labels_count_temp);

    int labels_count = stoi(ltrim(rtrim(labels_count_temp)));

    vector<string> labels(labels_count);

    for (int i = 0; i < labels_count; i++) {
        string labels_item;
        getline(cin, labels_item);

        labels[i] = labels_item;
    }

    string dailyCount_temp;
    getline(cin, dailyCount_temp);

    int dailyCount = stoi(ltrim(rtrim(dailyCount_temp)));

    int result = maxCost(cost, labels, dailyCount);

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

// problem source: https://www.hackerrank.com/challenges/marcs-cakewalk/problem
// discussion reference: https://mjmjmj98.tistory.com/38
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'marcsCakewalk' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY calorie as parameter.
 */

long marcsCakewalk(vector<int> calorie) {
    int calorie_size = calorie.size();
    sort(calorie.begin(), calorie.end());
    long min_value = 0;
    for (int i = 0; i < calorie_size; i++)
        min_value += pow(2, i) * calorie[calorie_size - 1 - i];
    return min_value;

    // Terminated due to timeout
    // int calorie_size = calorie.size();
    // vector<int> perm(calorie_size);
    // long min_value = LONG_MAX;
    // for (int i = 0; i < calorie_size; i++)
    //     perm[i] = i;
    // do {
    //     int value = 0;
    //     int i = 0;
    //     for (auto it = perm.begin(); it != perm.end(); ++it) {
    //         value += pow(2, i) * calorie[*it];
    //         i++;
    //     }
    //     if (min_value > value)
    //         min_value = value;
    // } while (next_permutation(perm.begin(), perm.end()));
    // return min_value;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string calorie_temp_temp;
    getline(cin, calorie_temp_temp);

    vector<string> calorie_temp = split(rtrim(calorie_temp_temp));

    vector<int> calorie(n);

    for (int i = 0; i < n; i++) {
        int calorie_item = stoi(calorie_temp[i]);

        calorie[i] = calorie_item;
    }

    long result = marcsCakewalk(calorie);

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

// problem source: https://www.hackerrank.com/challenges/beautiful-triplets/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'beautifulTriplets' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */
 int beautifulTriplets(int d, vector<int> arr) {
     int arr_size = arr.size();
     vector<int> middle_result;
     int count = 0;
     for (int i = 0; i < arr_size - 2; i++) {
         for (int j = i + 1; j < arr_size - 1; j++) {
             if (arr[j] - arr[i] == d) {
                 middle_result.push_back(arr[j]);
             }
         }
     }
     int middle_result_size = middle_result.size();
     for (int i = 0; i < middle_result_size; i++) {
         for (int j = 2; j < arr_size; j++) {
             if (arr[j] - middle_result[i] == d)
                     count++;
         }
     }
     return count;

    // Terminated due to timeout
    // int arr_size = arr.size();
    // int count = 0;
    // for (int i = 0; i < arr_size - 2; i++) {
    //     for (int j = i + 1; j < arr_size - 1; j++) {
    //         for (int k = j + 1; k < arr_size; k++) {
    //             if (arr[j] - arr[i] == d) {
    //                 if (arr[j] - arr[i] == arr[k] - arr[j])
    //                     count++;
    //             }
    //         }
    //     }
    // }
    // return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = beautifulTriplets(d, arr);

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

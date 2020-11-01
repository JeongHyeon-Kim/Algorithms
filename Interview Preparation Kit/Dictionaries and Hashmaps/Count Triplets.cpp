// problem source: https://www.hackerrank.com/challenges/count-triplets-1/problem
// discussion reference: https://nukeguys.tistory.com/155, https://www.hackerrank.com/challenges/count-triplets-1/forum/comments/864497
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    // 5/13 test cases failed
    // map<long, int> number_count;
    // int arr_size = arr.size();
    // long result = 0;
    // for (int i = 0; i < arr_size; i++)
    //     number_count[arr[i]]++;
    // if (r == 1) {
    //     result = arr_size;
    //     return result;
    // }
    // for (auto it = number_count.begin(); it != number_count.end(); it++) {
    //     if (it->first % r == 0) {
    //         long found_key = it->first, left_key = found_key / r, right_key = found_key * r;
    //         if ( (number_count.find(left_key) != number_count.end())
    //             && (number_count.find(right_key) != number_count.end()) ) {
    //             result += number_count[found_key] * number_count[left_key] * number_count[right_key];
    //         }
    //     }
    // }
    // return result;

    long counter = 0;
    double rr = r; // for test case 3

    unordered_map<double, long> left; // can dividing
    unordered_map<double, long> right; // can multiplying

    for (auto i : arr)
        right[i]++; // counting
    for (auto j : arr){
        right[j]--; // testing
        counter += left[j / rr] * right[j * rr];
        left[j]++;
    }

    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

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

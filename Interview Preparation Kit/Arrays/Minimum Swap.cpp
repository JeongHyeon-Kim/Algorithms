// problem source: https://www.hackerrank.com/challenges/minimum-swaps-2/problem
// discussion reference: https://www.hackerrank.com/challenges/minimum-swaps-2/forum/comments/458759
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    // Pass only one case
    // int pivot_index = arr.size() / 2;
    // int count = 0;
    // int left_sort = pivot_index;
    // while (left_sort > 0) {
    //     for (int i = 0; i < left_sort; i++) {
    //         if (arr[i] > arr[left_sort]) {
    //             int tmp = arr[left_sort];
    //             arr[left_sort] = arr[i];
    //             arr[i] = tmp;
    //             count++;
    //         }
    //     }
    //     left_sort--;
    // }
    // int right_sort = pivot_index;
    // while (right_sort < arr.size()) {
    //     for (int i = right_sort; i < arr.size(); i++) {
    //         if (arr[i] < arr[right_sort]) {
    //             int tmp = arr[right_sort];
    //             arr[right_sort] = arr[i];
    //             arr[i] = tmp;
    //             count++;
    //         }
    //     }
    //     right_sort++;
    // }
    // return count;

    int count=0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != i + 1) { // Confirm same with position  elements of the array and position sorting when ascending order
                int pivot = i;
                while(arr[pivot] != i+1)
                    pivot++;
                int tmp = arr[pivot];
                arr[pivot] = arr[i];
                arr[i] = tmp;
                count++;
            }
        }
        return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

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

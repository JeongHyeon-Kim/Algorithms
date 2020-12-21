// problem source: https://www.hackerrank.com/challenges/balanced-brackets/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    // Occured segmentation fault in 18 cases
    int s_size = s.size();
    stack<char> balanced;
    char start_bracket[3] = {'(', '{', '['};
    char end_bracket[3] =  {')', '}', ']'};

    if (s_size % 2 == 1)
        return "NO";
    else {
        for (int i = 0; i < s_size; i++) {
            for (int j = 0; j < 3; j++) {
                if (s[i] == start_bracket[j])
                    balanced.push(s[i]);
                else if (s[i] == end_bracket[j]) {
                    if (balanced.top() == start_bracket[j])
                        balanced.pop();
                    else
                        return "NO";
                }
            }
        }
    }
    if (balanced.empty())
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

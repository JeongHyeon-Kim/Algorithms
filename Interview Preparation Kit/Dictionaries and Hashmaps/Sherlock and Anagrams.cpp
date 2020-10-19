// problem source: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
// discussion reference: https://www.hackerrank.com/challenges/sherlock-and-anagrams/forum/comments/279122
#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
  int count = 0;
  for (int i = 1; i < s.length(); i++) { // '=' condition make included whole word
      // Checking by step by word count
      vector<string> sub_str;

      for (int j = 0; j + i <= s.length(); j++) { // Creating substring
          cout << s.substr(j,i) << endl;
          sub_str.push_back(s.substr(j,i));
      }

      for (int a = 0; a < sub_str.size(); a++) { // Checking anagrams
            for (int b = a + 1; b < sub_str.size(); b++) {
                bool is_anagrams = true;

                int comp_first[26] = {0};
                int comp_second[26] = {0};

                for (int i = 0; i < sub_str[a].size(); i++) {
                    comp_first[sub_str[a][i] - 'a']++;
                }
                for (int i = 0; i < sub_str[b].size(); i++) {
                    comp_second[sub_str[b][i] - 'a']++;
                }
                for (int i = 0; i < 26; i++) {
                    if (comp_first[i] != comp_second[i])
                        is_anagrams = false;
                }
                if (is_anagrams)
                    count++;
            }
        }
  }
  return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

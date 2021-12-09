// problem source: https://leetcode.com/contest/weekly-contest-270/problems/finding-3-digit-even-numbers/
// https://ansohxxn.github.io/algorithm/permutation/#%EC%9E%AC%EA%B7%80%EB%A1%9C-%EA%B5%AC%ED%98%84%ED%95%9C-%EC%BD%94%EB%93%9C-1
// https://pythonq.com/so/c%2B%2B/805667
class Solution {
public:
    void swap(int& a, int& b)
    {
        char temp = a;
        a = b;
        b = temp;
    }

    void permutation(vector<int> data, int depth, int n, int r, vector<int>& result) {
        if (depth == r && data[0] != 0) {
            stringstream ss;
            int middle_result;
            for(int i = 0; i < r; i++)
                ss << data[i];
            ss >> middle_result;
            if (middle_result % 2 == 0)
                result.push_back(middle_result);
            return;
        }

        for(int i = depth; i < n; i++) {
            swap(data[depth], data[i]);
            permutation(data, depth + 1, n, r, result);
            swap(data[depth], data[i]);
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        int digits_size = digits.size();
        vector<int> result;
        sort(digits.begin(), digits.end());
        permutation(digits, 0, digits_size, 3, result); // get three digits
        return result;
    }
};


class Solution {
public:
    void Combination(vector<int> arr, vector<int> comb, int index, int depth) {
        if (depth == comb.size()) {
            for(int i = 0; i < comb.size(); i++)
                cout << comb[i] << " ";
            cout << endl;
            return;
        } else {
            for(int i = index; i < arr.size(); i++) {
                comb[depth] = arr[i];
                Combination(arr, comb, i + 1, depth + 1);
            }
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        // 완전 탐색을 하되 result에는 조건에 맞는 것만 넣기
        // int digits_size = digits.size();
        vector<int> result;
        int r = 3;
        vector<int> comb(r);
        sort(digits.begin(), digits.end());
        Combination(digits, comb, 0, 0);  // {'a', 'b', 'c', 'd', 'e'}의 '5C3' 구하기



        // 2자리 숫자 컷
        // 홀수 컷

//         while(next_permutation(digits.begin(), digits.end()))
//             cout

//         for (int i = 0; i < digits_size; i++)
//             cout << digits[i] << " ";
//         cout << endl;



        return result;
    }
};

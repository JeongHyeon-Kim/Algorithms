// problem source: https://leetcode.com/problems/permutation-sequence/
// discussion reference: https://leetcode.com/problems/permutation-sequence/solutions/2502436/c-100-fastest-solution-best-approach-with-good-explanation-easy-to-understand-1/
class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++) {
            factorial = factorial * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k = k - 1;
        string answer = "";
        while (true) {
            answer = answer + to_string(numbers[k / factorial]);
            numbers.erase(numbers.begin() + k / factorial);
            if (numbers.size() == 0)
                break;
            k = k % factorial;
            factorial = factorial / numbers.size();
        }
        return answer;
    }
};

/*
순열에 대한 조합의 경우들을 vector에 저장하고 k-1 번째의 요소를 출력한다.
Time Limit Exceeded at 137 case 
n = 9, k = 161191
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<vector<int>> result;
        string int_to_string;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        result.push_back(nums);
        while(next_permutation(nums.begin(), nums.end()))
            result.push_back(nums);
        // for (int i = 0; i < result.size(); i++) {
        //     for (int j = 0; j < result[0].size(); j++)
        //         cout << result[i][j];
        //     cout << endl;
        // }
        for (int i = 0; i < n; i++)
            // cout << result[k-1][i];
            int_to_string += to_string(result[k-1][i]);
        return int_to_string;
    }
};
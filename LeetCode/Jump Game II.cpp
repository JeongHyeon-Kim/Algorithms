// problem source: https://leetcode.com/problems/jump-game-ii/
// discussion reference: https://leetcode.com/problems/jump-game-ii/discuss/1192401/Easy-Solutions-w-Explanation-or-Optimizations-from-Brute-Force-to-DP-to-Greedy-BFS

// 문제 이해
// 0에서 시작해서 배열의 마지막까지 도달하려면 최소 얼마나 점프를 해야 하는가?
// 0-index 배열 사용 (0 1 2 3 4)
// Test Case 별 이해
// TC 1. [2,3,1,1,4]
// 0이 현 위치이며 0에서 최대 nums[0] = 2만큼 점프 가능(점프의 최대 길이)하다는 의미
// stage1. 0 -> 1까지 1칸 점프
// stage2. 1 -> 4까지 까지 3(nums[1])칸 점프
// 해당 점프가 최소
// TC 2. [2,3,0,1,4]
// 초기 위치와 nums[0]는 동일
// 다만, nums[2]의 경우 0이 들어가 있고 해당 위치로 점프 시 배열의 끝으로 이동 불가
// 요약: num[0]에서 num[4]로 가는 것 중 nums[i]만큼 점프를 뛸 수 있는데 그 중 빠르게 갈 수 있는 것을 택해야 함

// try 2
// Runtime: 741 ms, faster than 10.44% of C++ online submissions for Jump Game II.
// Memory Usage: 18.2 MB, less than 6.80% of C++ online submissions for Jump Game II.
class Solution {
public:
    int jump(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> dynamic_programming(nums_size, 10001);
        return solve(nums, dynamic_programming, 0);
    }
    int solve(vector<int>& nums, vector<int>& dynamic_programming, int position) {
        int nums_size = nums.size();
        if (position >= nums_size - 1) // end condition
            return 0;
        if (dynamic_programming[position] != 10001)
            return dynamic_programming[position];
        for (int j = 1; j <= nums[position]; j++)
            dynamic_programming[position] = min(dynamic_programming[position], 1 + solve(nums, dynamic_programming, position + j));
        return dynamic_programming[position];
    }
};

// try 1
class Solution {
public:
    int jump(vector<int>& nums) {
        int nums_size = nums.size();
        int count = 0;
        for (int i = 0; i < nums_size; i++) { // 첫 시작 & 이동 배열
            // cout << nums[i] << " ";
            vector<int> checking(nums[i] + 1);
            for (int j = 0; j <= nums[i]; j++) { // 경우의 수
                if (nums[i] == 0)
                    continue;
                if (i + j < nums_size) {
                    checking[j] = i + j;
                }
            }
        }
        return count;
    }
};
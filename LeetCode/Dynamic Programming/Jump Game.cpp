// problem source: https://leetcode.com/problems/jump-game/
// dicussion reference: https://leetcode.com/problems/jump-game/discuss/20917/Linear-and-simple-solution-in-C++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nums_size = nums.size();
        int nums_index = 0;
        for (int can_reach = 0; nums_index < nums_size && nums_index <= can_reach; nums_index++)
            can_reach = max(nums_index + nums[nums_index], can_reach); // iterate and update the maximal index that it can reach
        return nums_index == nums_size;
    }

    // bool recursive_method(vector<int>& nums, int current_index, int max_jumping) {
    //     if (current_index >= nums.size() - 1)
    //         return false;
    //
    //     for (int i = 1; i <= max_jumping; i++) {
    //         if (current_index + i == nums.size() - 1) {
    //             cout << "in" << endl;
    //             return true;
    //         } else
    //             recursive_method(nums, current_index + i, nums[i]);
    //     }
    //
    //     return true;
    // }

    // bool canJump(vector<int>& nums) {
    //     // int first_max_jumping = nums[0];
    //     // return recursive_method(nums, 0, first_max_jumping);
    //     // bool result;
    //     int nums_size = nums.size();
    //
    //     for (int start_index = 0; start_index < nums_size; start_index++) { // for start_index
    //         int next_index = 0;
    //         while (next_index < nums_size) {
    //             int max_jumping = nums[next_index];
    //             for (int jump = start_index + 1; jump <= start_index + max_jumping; jump++) {
    //                 if (start_index + jump == nums_size - 1)
    //                     return true;
    //                 else
    //                     next_index = start_index + jump;
    //             }
    //         }
    //     }
    //     return false;
    }
};

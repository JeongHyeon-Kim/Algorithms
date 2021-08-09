// problem source: https://leetcode.com/problems/subarray-sum-equals-k/
// discussion reference: https://leetcode.com/problems/subarray-sum-equals-k/discuss/1390419/O(n)-using-hashmap-in-c%2B%2B
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int nums_size = nums.size();
        int sum = 0;
        int count = 0;
        unordered_map<int, int> data;
        for (int i = 0; i < nums_size; i++) {
            sum += nums[i];
            if (sum == k)
                count++;
            if (data.find(sum - k) != data.end()) // found
                count += data[sum - k];
            data[sum]++;
        }
        return count;
    }
};

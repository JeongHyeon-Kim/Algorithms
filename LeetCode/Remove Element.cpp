// problem source: https://leetcode.com/problems/remove-element/
// usage reference: https://backhugger.tistory.com/45
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto it = nums.begin(); it != nums.end();) {
            if (*it == val)
                it = nums.erase(it);
            else
                it++;
        }
        return nums.size();
    }
};

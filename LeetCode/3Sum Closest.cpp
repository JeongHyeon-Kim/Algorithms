// problem source: https://leetcode.com/problems/3sum-closest/
// basic knowledge reference: https://m.blog.naver.com/sjjwjj/221463335072
class Solution {
public:
    // Time Limit Exceeded with "[-88,80,-32,32,-89,42,80,-79,-99,78,-87,-40,13,54,-25,5,-75,-47,35,-65,60,-93,-29,46,9,-94,52,67,-68,-32,-23,4,88,3,63,-80,41,-28,8,-97,97,79,55,81,64,48,-83,-84,-36,-25,-21,53,42,31,-88,100,-83,-99,56,-27,24,39,94,8,-76,60,-38,92,-60,-97,83,-63,-7,70,73,15,3,-69,-43,-58,78,-48,63,62,95,-35,88,9,-25,-23,-74,-27,60,-6,40,-54,14,99,73,-65,-18,-78,-29,-66,-64,86,94,46,75,-89,49,-64,-76,5,56,14,1,-45,-10,17,-31,-43,-82,-10,7,-3,73,85,96,-29,92,-57,-1,56,44,52,8,67,-50,-11,-8,-13,48,62,-20,-27,100,-71,52,-79,-66,37,-57,-29,-13,65,-88,34,-8,-44,-52,-41,88,-52,71,0,93,42,7,23,-43,7,-98,-31,3,1,79,-74,-86,-71,89,58,-76,63,36,-70], 55"
    const int select = 3;
    vector<int> selected;
    vector<int> copied;
    vector<int> compare;
    void combination(int depth, int index) {
        if (index > select - 1) { // selected's index
            int sum = 0;
            for (int i = 0; i < select; i++)
                sum += selected[i];
            compare.push_back(sum);
            return;
        }

        if (depth > copied.size() - 1) // over search
            return;

        selected[index] = copied[depth]; // save in selected array

        combination(depth + 1, index + 1);
        combination(depth + 1, index);
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int nums_size = nums.size();
        int minimal = INT_MAX;
        int result;
        if (nums_size == 3)
            return nums[0] + nums[1] + nums[2];
        selected.resize(select, 0);
        copied.assign(nums.begin(), nums.end());
        combination(0, 0);
        int compare_size = compare.size();
        for (int i = 0; i < compare_size; i++) {
            int individual_compare = abs(target - compare[i]);
            if (minimal > individual_compare) {
                minimal = individual_compare;
                result = compare[i];
            }
        }
        return result;
    }
};

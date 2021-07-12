// problem source: https://leetcode.com/problems/trapping-rain-water/
// discussion reference: https://leetcode.com/problems/trapping-rain-water/discuss/1330328/Easy-C%2B%2B-solution
class Solution {
public:
    int trap(vector<int>& height) {
        int height_size = height.size();
        int left = 0;
        int right = 0;
        int trapped = 0;
        vector<int> max_on_left(height), max_on_right(height);
        for(int i = 0; i < height_size; i++) {
            left = max(left, height[i]);
            max_on_left[i] = left;
            int j = height_size - i - 1; // start in right of height's vector
            right = max(right, height[j]);
            max_on_right[j] = right;
        }
        for(int i = 0; i < height_size; i++)
            trapped += (min(max_on_left[i], max_on_right[i]) - height[i]);
        return trapped;

        // try 1
        // int max_height = 0;
        // int trapped = 0;
        // int height_size = height.size();
        // vector<int> diff;
        // for (int i = 0; i < height_size - 1; i++)
        //     diff.push_back(height[i + 1] - height[i]); // diff value for height
        // int diff_size = diff.size();
        // for (int i = 1; i < height_size - 1; i++) {
        //     if (diff[i - 1] > 0  && diff[i] < 0) {
        //         trapped -= diff[i];
        //     } else if (diff[i - 1] > 0  && diff[i] > 0) {
        //
        //     } else if (diff[i - 1] < 0  && diff[i] < 0) {
        //         trapped -= diff[i];
        //     } else if (diff[i - 1] < 0  && diff[i] > 0) {
        //         continue;
        //     }
        // }
        // return trapped;
    }
};

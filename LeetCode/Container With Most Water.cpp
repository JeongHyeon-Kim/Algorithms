// problem source: https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int height_size = height.size();
        int max_height = 0, second_max_height = 0;
        int max_height_location = -1, second_max_height_location = -1;
        int max_height_location2 = -1, second_max_height_location2 = -1;
        int result = 0;
        for (int i = 0; i < height_size; i++) {
            if (height[i] > max_height) {
                max_height = height[i];
                max_height_location = i;
            } else if (height[i] < max_height && height[i] > second_max_height) {
                second_max_height = height[i];
                second_max_height_location = i;
            } else if (height[i] == max_height) {
                max_height_location2 = i;
            } else if (height[i] == second_max_height) {
                second_max_height_location2 = i;
            }
        }
        if (max_height_location2 != -1)
            result = max(max_height * (max_height_location2 - max_height_location), second_max_height * (second_max_height_location - max_height_location));
        else
            result = second_max_height * (second_max_height_location2 - second_max_height_location);
        return result;
    }
};

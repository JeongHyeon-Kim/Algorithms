// problem source: https://leetcode.com/problems/container-with-most-water/
// discussion reference: https://leetcode.com/problems/container-with-most-water/discuss/1476775/Simple-C%2B%2B-ororCode-With-Explanation-oror-Easy-to-understand
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int i = 0; // from first to backward
        int j = height.size() - 1; // from last to forward
        while (i < j) {
            // calculate height all cases on condition
            result = max(result, (j - i) * min(height[i], height[j]));
            if (height[i] <= height[j])
                i++;
            else // height[i] > height[j]
                j--;
        }
        return result;

        // wrong with [1,2,4,3]
        // int height_size = height.size();
        // int max_height = 0, second_max_height = 0;
        // int max_height_location = -1, second_max_height_location = -1;
        // int max_height_location2 = -1, second_max_height_location2 = -1;
        // int result = 0;
        // for (int i = 0; i < height_size; i++) {
        //     if (height[i] > max_height) {
        //         // max value is changing and setting second max value
        //         second_max_height = max_height;
        //         second_max_height_location = max_height_location;
        //         max_height = height[i];
        //         max_height_location = i;
        //     } else if (height[i] < max_height && height[i] > second_max_height) {
        //         // cout << i << " with " << height[i] << endl;
        //         second_max_height = height[i];
        //         second_max_height_location = i;
        //     } else if (height[i] == max_height) {
        //         cout << i;
        //         cout << " is same with max" << endl;
        //         max_height_location2 = i;
        //     } else if (height[i] == second_max_height) {
        //         cout << i;
        //         cout << " is same with second max" << endl;
        //         second_max_height_location2 = i;
        //     }
        // }
        // cout << max_height << " " << second_max_height << endl;
        // cout << max_height_location << " " << second_max_height_location << endl;
        // cout << max_height_location2 << " " << second_max_height_location2  << endl;
        // if (max_height_location2 != -1)
        //     result = max(max_height * (max_height_location2 - max_height_location), second_max_height * (second_max_height_location - max_height_location));
        // else if (max_height_location2 == -1 && second_max_height_location2 == -1)
        //     result = second_max_height * abs(max_height_location - second_max_height_location);
        // else // max_height_location2 == -1
        //     result = second_max_height * (second_max_height_location2 - second_max_height_location);
        //
        // return result;

        // wrong with [1,2,1]
        // int height_size = height.size();
        // int max_height = 0, second_max_height = 0;
        // int max_height_location = -1, second_max_height_location = -1;
        // int max_height_location2 = -1, second_max_height_location2 = -1;
        // int result = 0;
        // for (int i = 0; i < height_size; i++) {
        //     if (height[i] > max_height) {
        //         max_height = height[i];
        //         max_height_location = i;
        //     } else if (height[i] < max_height && height[i] > second_max_height) {
        //         second_max_height = height[i];
        //         second_max_height_location = i;
        //     } else if (height[i] == max_height) {
        //         max_height_location2 = i;
        //     } else if (height[i] == second_max_height) {
        //         second_max_height_location2 = i;
        //     }
        // }
        // if (max_height_location2 != -1)
        //     result = max(max_height * (max_height_location2 - max_height_location), second_max_height * (second_max_height_location - max_height_location));
        // else
        //     result = second_max_height * (second_max_height_location2 - second_max_height_location);
        // return result;
    }
};

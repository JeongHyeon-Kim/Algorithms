// problem source: https://leetcode.com/problems/robot-bounded-in-circle/
// discussion reference: https://leetcode.com/problems/robot-bounded-in-circle/discuss/1346150/Simple-C%2B%2B-Solution-with-just-three-Variables
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int instructions_size = instructions.size();
        int x = 0, y = 0;
        int direction = 0;
        for (int i = 0; i < instructions_size; i++) {
            if (instructions[i] == 'G') {
                if (direction == 0) // north
                    y++;
                if (direction == 1) // east
                    x++;
                if (direction == 2) // west
                    y--;
                if (direction == 3) // south
                    x--;
            } else {
                if (instructions[i] == 'L') {
                    direction--;
                    direction = direction + 4;
                    direction = direction % 4;
                } else { // 'R'
                    direction++;
                    direction = direction % 4; // return to origin
                }
            }
        }
        if (direction == 0 && (x != 0 || y != 0))
            return false;
        return true;
    }
};

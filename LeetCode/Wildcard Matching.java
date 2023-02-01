// problem source: https://leetcode.com/problems/wildcard-matching/

// discussion reference: https://leetcode.com/problems/wildcard-matching/discuss/17812/My-java-DP-solution-using-2D-table
// Runtime: 34 ms, faster than 59.29% of Java online submissions for Wildcard Matching.
// Memory Usage: 42.7 MB, less than 73.18% of Java online submissions for Wildcard Matching.

class Solution {
    public boolean isMatch(String s, String p) {
        int s_length = s.length();
        int p_length = p.length();
        boolean[][] match = new boolean[s_length + 1][p_length + 1];
        match[s_length][p_length] = true; // init by true
        for (int i = p_length - 1; i >= 0; i--) { // checking from backward
            if (p.charAt(i) != '*') // checking multiple matching
                break;
            else
                match[s_length][i] = true;
        }
        for (int i = s_length - 1; i >= 0; i--) {
            for (int j = p_length - 1; j >= 0; j--) {
                if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?') // same or single matching
                    match[i][j] = match[i + 1][j + 1]; // right bottom to left top
                else if (p.charAt(j) == '*')
                    match[i][j] = match[i + 1][j] || match[i][j + 1]; // result is combine right to left and bottom to top
                else // not matching case, continuous result by logic
                    match [i][j] = false;

            }
        }
        return match[0][0];
    }
}

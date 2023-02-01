// problem source: https://leetcode.com/problems/wildcard-matching/

// disscustion reference: https://leetcode.com/problems/wildcard-matching/discuss/17810/Linear-runtime-and-constant-space-solution
// Runtime: 5 ms, faster than 78.33% of C online submissions for Wildcard Matching.
// Memory Usage: 5.8 MB, less than 85.00% of C online submissions for Wildcard Matching.

bool isMatch(char * s, char * p){
    const char* star = NULL; // star location
    const char* ss = s; // copy s's location pointer
    while (*s) { // check s
        if (*p == '?' || *p == *s) { // single matching
            s++;
            p++;
            continue;
        }
        if (*p == '*') { // multiple matching
            star = p++;
            ss = s;
            continue;
        }
        if (star) { // if star location is exist by second condition
            // advancing one location
            p = star + 1;
            s = ++ss;
            continue;
        }
        return false;
    }
    while (*p == '*') // check remaining
        p++;
    return !*p;
}

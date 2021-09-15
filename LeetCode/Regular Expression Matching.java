// problem source: https://leetcode.com/problems/regular-expression-matching/
// discussion reference: https://leetcode.com/problems/regular-expression-matching/discuss/1459888/One-line-Java-solution
// class reference: https://coding-factory.tistory.com/529
class Solution {
    public boolean isMatch(String s, String p) {
        // using class in java
        return java.util.regex.Pattern.compile(p).matcher(s).matches();
    }
}

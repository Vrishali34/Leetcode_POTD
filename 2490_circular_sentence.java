class Solution {
    public boolean isCircularSentence(String s) {
        return s.charAt(0) == s.charAt(s.length() - 1) && IntStream.range(1, s.length() - 1).allMatch(i -> s.charAt(i) != ' ' || s.charAt(i - 1) == s.charAt(i + 1));
    }
}

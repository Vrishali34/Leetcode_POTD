class Solution {
    public boolean canConstruct(String x, int y) {
        if (y > x.length()) return false;
        int[] z = new int[26];
        int c = 0;
        for (char a : x.toCharArray()) z[a - 'a']++;
        for (int b : z) c += b % 2;
        return c <= y;
    }
}

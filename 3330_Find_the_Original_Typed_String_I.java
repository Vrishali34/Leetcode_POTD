class Solution {
    public int possibleStringCount(String z) {
        int c = 1, i = 0, n = z.length();
        while (i < n) {
            int j = i;
            while (j + 1 < n && z.charAt(j + 1) == z.charAt(i)) j++;
            c += j - i;
            i = j + 1;
        }
        return c;
    }
}

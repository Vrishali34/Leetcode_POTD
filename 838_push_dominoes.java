class Solution {
    public String pushDominoes(String s) {
        char[] a = s.toCharArray();
        int i = 0, n = a.length;
        while (i < n) {
            if (a[i] != '.') { i++; continue; }
            int j = i;
            while (j < n && a[j] == '.') j++;
            char left = i > 0 ? a[i - 1] : '.';
            char right = j < n ? a[j] : '.';
            if (left == 'R' && right == 'L') {
                int m = j - i;
                for (int k = 0; k < m / 2; k++) {
                    a[i + k] = 'R';
                    a[j - 1 - k] = 'L';
                }
            } else if (left == 'R') {
                Arrays.fill(a, i, j, 'R');
            } else if (right == 'L') {
                Arrays.fill(a, i, j, 'L');
            }
            i = j;
        }
        return new String(a);
    }
}

class Solution {
    public long minSum(int[] a, int[] b) {
        long s1 = 0, s2 = 0; int z1 = 0, z2 = 0;
        for (int i : a) if (i == 0) z1++; else s1 += i;
        for (int i : b) if (i == 0) z2++; else s2 += i;
        if (z1 == 0 && s1 < s2 + z2) return -1;
        if (z2 == 0 && s2 < s1 + z1) return -1;
        return Math.max(s1 + z1, s2 + z2);
    }
}

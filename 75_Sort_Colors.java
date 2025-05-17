class Solution {
    public void sortColors(int[] y) {
        int[] f = new int[3];
        for (int z : y) f[z]++;
        int i = 0;
        for (int j = 0; j < 3; j++)
            while (f[j]-- > 0) y[i++] = j;
    }
}

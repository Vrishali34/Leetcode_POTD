class Solution {
    public boolean isArraySpecial(int[] z) {
        int j = z.length;
        for (int i = 0; i < j - 1; i++) 
            if ((z[i] % 2) == (z[i + 1] % 2)) return false;
        return true;
    }
}

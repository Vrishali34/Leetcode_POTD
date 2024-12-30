class Solution {
    int P = (int) 1e9 + 7;
    int[] memo = new int[100001];
    
    int foom(int l, int h, int z, int o, int len) {
        if (len > h) return 0;
        if (memo[len] != -1) return memo[len];
        int grab = (len >= l && len <= h) ? 1 : 0;
        return memo[len] = (grab + foom(l, h, z, o, len + z) + foom(l, h, z, o, len + o)) % P;
    }

    public int countGoodStrings(int l, int h, int z, int o) {
        Arrays.fill(memo, -1);
        return foom(l, h, z, o, 0);
    }
}

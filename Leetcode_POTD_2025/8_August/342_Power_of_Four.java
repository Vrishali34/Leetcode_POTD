class Solution {
    public boolean isPowerOfFour(int n) {
        if (n <= 0) return false;
        double a_p = Math.log(n) / Math.log(4);
        return a_p == Math.floor(a_p);
    }
}

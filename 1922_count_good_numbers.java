class Solution {
    public int countGoodNumbers(long a) {
        return (int)(q(5, (a+1)/2) * q(4, a/2) % M);
    }
    final long M = 1_000_000_007;
    long q(long b, long e) {
        long r = 1;
        while(e > 0) {
            if((e & 1) == 1) r = r * b % M;
            b = b * b % M;
            e >>= 1;
        }
        return r;
    }
}

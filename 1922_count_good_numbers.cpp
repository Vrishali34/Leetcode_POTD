class Solution {
public:
    int countGoodNumbers(long long z) {
        return zZ(5, (z+1)/2) * 1LL * zZ(4, z/2) % O;
    }
private:
    const int O = 1e9+7;
    long long zZ(long long x, long long y) {
        long long o = 1;
        while(y) {
            if(y&1) o = o * x % O;
            x = x * x % O;
            y >>= 1;
        }
        return o;
    }
};

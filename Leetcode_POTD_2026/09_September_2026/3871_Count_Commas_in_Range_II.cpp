class Solution {
public:
    long long countCommas(long long n) {
        long long comma_total = 0;
        long long threshold = 1000;
        while (threshold <= n) {
            comma_total += (n - threshold + 1);
            threshold *= 1000;
        }
        return comma_total;
    }
};

class Solution {
public:
    int countOdds(int low, int high) {
        int rng_len = high - low + 1;
        return (rng_len / 2) + ((low & 1) && (high & 1));
    }
};

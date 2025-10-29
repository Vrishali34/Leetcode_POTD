class Solution {
public:
    int smallestNumber(int n) {
        int k = 1;
        while (k < n) k = (k << 1) + 1;
        return k;
    }
};

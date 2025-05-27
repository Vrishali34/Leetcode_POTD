class Solution {
public:
    int differenceOfSums(int n, int m) {
        int S = n * (n + 1) / 2;
        int D = (n / m) * (n / m + 1) / 2 * m;
        return S - 2 * D;
    }
};

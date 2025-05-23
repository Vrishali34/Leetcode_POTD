class Solution {
public:
    long long maximumValueSum(std::vector<int>& eL, int iN, std::vector<std::vector<int>>& bT) {
        long long pS = 0;
        int tC = 0;
        long long lP = 2e9 + 7;
        for (int qV : eL) {
            long long xV = qV ^ iN;
            pS += std::max(static_cast<long long>(qV), xV);
            if (xV > qV) {
                tC++;
            }
            lP = std::min(lP, std::abs(static_cast<long long>(qV) - xV));
        }
        if (tC % 2 == 0) {
            return pS;
        }
        return pS - lP;
    }
};

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int modVal = 1e9 + 7;
        vector<vector<int>> subGcdMat(201, vector<int>(201, 0));
        subGcdMat[0][0] = 1;
        for (int curNum : nums) {
            vector<vector<int>> nextGcdMat(201, vector<int>(201, 0));
            for (int gcdSeq1 = 0; gcdSeq1 <= 200; ++gcdSeq1) {
                for (int gcdSeq2 = 0; gcdSeq2 <= 200; ++gcdSeq2) {
                    long long waysCnt = subGcdMat[gcdSeq1][gcdSeq2];
                    if (!waysCnt) continue;
                    nextGcdMat[gcdSeq1][gcdSeq2] = (nextGcdMat[gcdSeq1][gcdSeq2] + waysCnt) % modVal;
                    int newGcd1 = gcdSeq1 == 0 ? curNum : std::gcd(gcdSeq1, curNum);
                    nextGcdMat[newGcd1][gcdSeq2] = (nextGcdMat[newGcd1][gcdSeq2] + waysCnt) % modVal;
                    int newGcd2 = gcdSeq2 == 0 ? curNum : std::gcd(gcdSeq2, curNum);
                    nextGcdMat[gcdSeq1][newGcd2] = (nextGcdMat[gcdSeq1][newGcd2] + waysCnt) % modVal;
                }
            }
            subGcdMat = move(nextGcdMat);
        }
        long long pairsAns = 0;
        for (int matchGcd = 1; matchGcd <= 200; ++matchGcd) {
            pairsAns = (pairsAns + subGcdMat[matchGcd][matchGcd]) % modVal;
        }
        return pairsAns;
    }
};

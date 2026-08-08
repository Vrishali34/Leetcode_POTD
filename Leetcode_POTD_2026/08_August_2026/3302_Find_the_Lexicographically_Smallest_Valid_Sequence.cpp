class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int lenSrc = word1.size(), lenTgt = word2.size();
        vector<int> tailMatch(lenSrc + 1, 0);
        for (int pos = lenSrc - 1; pos >= 0; pos--) {
            tailMatch[pos] = tailMatch[pos + 1];
            if (tailMatch[pos] < lenTgt && word1[pos] == word2[lenTgt - 1 - tailMatch[pos]])
                tailMatch[pos]++;
        }
        vector<int> chosenIdx(lenTgt, -1);
        int srcPtr = 0, tgtPtr = 0; bool swapUsed = false;
        while (srcPtr < lenSrc && tgtPtr < lenTgt) {
            if (word1[srcPtr] == word2[tgtPtr]) { chosenIdx[tgtPtr] = srcPtr; srcPtr++; tgtPtr++; }
            else if (!swapUsed && tailMatch[srcPtr + 1] >= lenTgt - tgtPtr - 1) { chosenIdx[tgtPtr] = srcPtr; swapUsed = true; srcPtr++; tgtPtr++; }
            else srcPtr++;
        }
        if (tgtPtr < lenTgt) return {};
        return chosenIdx;
    }
};

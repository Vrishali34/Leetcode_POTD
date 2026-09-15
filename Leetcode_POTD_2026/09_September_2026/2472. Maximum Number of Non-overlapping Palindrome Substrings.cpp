class Solution {
public:
    int maxPalindromes(string s, int k) {
        int strLen = s.size();
        vector<int> dpCount(strLen + 1, 0);

        auto isPalinRange = [&](int leftIdx, int rightIdx) {
            while (leftIdx < rightIdx) {
                if (s[leftIdx] != s[rightIdx]) return false;
                leftIdx++; rightIdx--;
            }
            return true;
        };

        for (int endIdx = 1; endIdx <= strLen; endIdx++) {
            dpCount[endIdx] = dpCount[endIdx - 1];

            int startShort = endIdx - k;
            if (startShort >= 0 && isPalinRange(startShort, endIdx - 1))
                dpCount[endIdx] = max(dpCount[endIdx], dpCount[startShort] + 1);

            int startLong = endIdx - k - 1;
            if (startLong >= 0 && isPalinRange(startLong, endIdx - 1))
                dpCount[endIdx] = max(dpCount[endIdx], dpCount[startLong] + 1);
        }

        return dpCount[strLen];
    }
};

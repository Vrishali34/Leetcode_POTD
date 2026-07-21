class Solution {
public:
    int maxActiveSectionsAfterTrade(string binaryStr) {
        string augmentedStr = "1" + binaryStr + "1";
        int totalLen = augmentedStr.size();

        // Step 1: build run-length encoded segments: {character, run length}
        vector<pair<char,int>> runSegments;
        int scanIdx = 0;
        while (scanIdx < totalLen) {
            int runEnd = scanIdx;
            while (runEnd < totalLen && augmentedStr[runEnd] == augmentedStr[scanIdx]) runEnd++;
            runSegments.push_back({augmentedStr[scanIdx], runEnd - scanIdx});
            scanIdx = runEnd;
        }

        // Step 2: count original active sections (1s) in s, not t
        int activeCount = count(binaryStr.begin(), binaryStr.end(), '1');

        // Step 3: scan internal 1-blocks only (skip first and last segment)
        int bestGain = 0;
        int segCount = runSegments.size();
        for (int segIdx = 1; segIdx < segCount - 1; segIdx++) {
            if (runSegments[segIdx].first == '1') {
                int gain = runSegments[segIdx-1].second + runSegments[segIdx+1].second;
                bestGain = max(bestGain, gain);
            }
        }

        // Step 4: apply best possible gain
        return activeCount + bestGain;
    }
};

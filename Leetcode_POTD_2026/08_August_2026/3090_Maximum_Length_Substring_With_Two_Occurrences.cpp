class Solution {
public:
    int maximumLengthSubstring(string s) {
        int charFreq[26] = {0};
        int winStart = 0, bestLen = 0;
        for (int winEnd = 0; winEnd < s.size(); winEnd++) {
            charFreq[s[winEnd] - 'a']++;
            while (charFreq[s[winEnd] - 'a'] > 2) charFreq[s[winStart++] - 'a']--;
            bestLen = max(bestLen, winEnd - winStart + 1);
        }
        return bestLen;
    }
};

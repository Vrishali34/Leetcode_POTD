class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int totalLen = s.size();
        vector<int> letterTally(26, 0);
        for (char ch : s) letterTally[ch - 'a']++;

        int oddTallyCnt = 0, oddLetterIdx = -1;
        for (int i = 0; i < 26; i++)
            if (letterTally[i] & 1) { oddTallyCnt++; oddLetterIdx = i; }

        bool oddLen = totalLen & 1;
        if ((!oddLen && oddTallyCnt) || (oddLen && oddTallyCnt != 1)) return "";

        vector<int> pairTally(26, 0);
        for (int i = 0; i < 26; i++) pairTally[i] = letterTally[i] / 2;
        char pivotChar = oddLen ? char('a' + oddLetterIdx) : 0;
        int wingLen = totalLen / 2;

        vector<int> matchedTally(26, 0);
        int matchableLen = wingLen;
        for (int i = 0; i < wingLen; i++) {
            int idx = target[i] - 'a';
            if (matchedTally[idx] + 1 > pairTally[idx]) { matchableLen = i; break; }
            matchedTally[idx]++;
        }

        auto weavePalin = [&](const string& wingStr) {
            string res = wingStr;
            if (oddLen) res += pivotChar;
            for (int i = wingStr.size() - 1; i >= 0; i--) res += wingStr[i];
            return res;
        };

        if (matchableLen == wingLen) {
            string exactWing = target.substr(0, wingLen);
            string palinGuess = weavePalin(exactWing);
            if (palinGuess > target) return palinGuess;
        }

        vector<int> leftoverTally(pairTally);
        for (int i = 0; i < matchableLen; i++) leftoverTally[target[i] - 'a']--;

        int probeStart = min(matchableLen, wingLen - 1);
        for (int j = matchableLen - 1; j >= probeStart && j >= 0; j--)
            leftoverTally[target[j] - 'a']++;

        for (int k = probeStart; k >= 0; k--) {
            int pickIdx = -1;
            for (int c = target[k] - 'a' + 1; c < 26; c++)
                if (leftoverTally[c] > 0) { pickIdx = c; break; }

            if (pickIdx != -1) {
                string wingStr = target.substr(0, k) + char('a' + pickIdx);
                leftoverTally[pickIdx]--;
                for (int c = 0; c < 26; c++)
                    wingStr += string(leftoverTally[c], char('a' + c));
                return weavePalin(wingStr);
            }
            if (k > 0) leftoverTally[target[k - 1] - 'a']++;
        }

        return "";
    }
};

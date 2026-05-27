class Solution {
public:
    int numberOfSpecialChars(string word) {
        int low_seen = 0, up_seen = 0, invalid_mask = 0;
        for (char ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                int bit = 1 << (ch - 'a');
                low_seen |= bit;
                if (up_seen & bit) invalid_mask |= bit;
            } else {
                up_seen |= 1 << (ch - 'A');
            }
        }
        return __builtin_popcount(low_seen & up_seen & ~invalid_mask);
    }
};

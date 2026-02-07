class Solution {
public:
    int minimumDeletions(string s) {
        int drop_count = 0, b_tally = 0;
        for (char glyph : s) {
            if (glyph == 'b') b_tally++;
            else drop_count = min(drop_count + 1, b_tally);
        }
        return drop_count;
    }
};

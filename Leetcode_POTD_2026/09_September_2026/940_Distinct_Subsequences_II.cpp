class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> last_seen_end(26, -1);
        long long total_subseq = 0;

        for (char ch : s) {
            int char_idx = ch - 'a';
            long long prev_total = total_subseq;
            total_subseq = (2 * total_subseq + 1) % MOD;
            if (last_seen_end[char_idx] != -1)
                total_subseq = (total_subseq - last_seen_end[char_idx] + MOD) % MOD;
            last_seen_end[char_idx] = prev_total + 1;
        }

        return (int)total_subseq;
    }
};

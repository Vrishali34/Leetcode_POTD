class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& seq_a, vector<int>& seq_b) {
        int seq_len = seq_a.size(), match_cnt = 0;
        vector<int> shared_pref(seq_len), item_freq(seq_len + 1, 0);
        for (int idx = 0; idx < seq_len; ++idx) {
            if (++item_freq[seq_a[idx]] == 2) ++match_cnt;
            if (++item_freq[seq_b[idx]] == 2) ++match_cnt;
            shared_pref[idx] = match_cnt;
        }
        return shared_pref;
    }
};

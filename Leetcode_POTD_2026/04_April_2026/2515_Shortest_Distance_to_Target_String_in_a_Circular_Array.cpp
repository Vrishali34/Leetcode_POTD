class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start_idx) {
        int n_len = words.size(), min_gap = n_len;
        for (int i = 0; i < n_len; ++i) {
            if (words[i] == target) {
                int direct_d = abs(i - start_idx);
                min_gap = min({min_gap, direct_d, n_len - direct_d});
            }
        }
        return min_gap == n_len ? -1 : min_gap;
    }
};

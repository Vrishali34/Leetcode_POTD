class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> p_sums(n + 1, 0);
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            p_sums[i + 1] = p_sums[i] + fruits[i][1];
            pos[i] = fruits[i][0];
        }
        int m_f = 0;
        for (int r = 0; r <= k; ++r) {
            int l_steps_needed = max(0, k - 2 * r);
            auto it_r = upper_bound(pos.begin(), pos.end(), startPos + r);
            auto it_l = lower_bound(pos.begin(), pos.end(), startPos - l_steps_needed);
            int e_r = distance(pos.begin(), it_r);
            int s_l = distance(pos.begin(), it_l);
            m_f = max(m_f, p_sums[e_r] - p_sums[s_l]);
        }
        for (int l = 0; l <= k; ++l) {
            int r_steps_needed = max(0, k - 2 * l);
            auto it_r = upper_bound(pos.begin(), pos.end(), startPos + r_steps_needed);
            auto it_l = lower_bound(pos.begin(), pos.end(), startPos - l);
            int e_r = distance(pos.begin(), it_r);
            int s_l = distance(pos.begin(), it_l);
            m_f = max(m_f, p_sums[e_r] - p_sums[s_l]);
        }
        return m_f;
    }
};

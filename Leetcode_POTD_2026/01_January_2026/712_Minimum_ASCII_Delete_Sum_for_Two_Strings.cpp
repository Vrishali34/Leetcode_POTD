class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len_a = s1.size(), len_b = s2.size();
        vector<int> cost_row(len_b + 1, 0);
        for (int j = 1; j <= len_b; ++j) cost_row[j] = cost_row[j - 1] + s2[j - 1];
        for (int i = 1; i <= len_a; ++i) {
            int prev_diag = cost_row[0];
            cost_row[0] += s1[i - 1];
            for (int j = 1; j <= len_b; ++j) {
                int temp_val = cost_row[j];
                if (s1[i - 1] == s2[j - 1]) cost_row[j] = prev_diag;
                else cost_row[j] = min(cost_row[j] + s1[i - 1], cost_row[j - 1] + s2[j - 1]);
                prev_diag = temp_val;
            }
        }
        return cost_row[len_b];
    }
};

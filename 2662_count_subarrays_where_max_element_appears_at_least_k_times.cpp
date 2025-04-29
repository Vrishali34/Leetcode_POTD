class Solution {
public:
    long long countSubarrays(vector<int>& z, int k) {
        int m = *max_element(begin(z), end(z)), l = 0, c = 0;
        long long q = 0;
        for (int r = 0; r < z.size(); ++r) {
            c += z[r] == m;
            while (c >= k) q += z.size() - r, c -= z[l++] == m;
        }
        return q;
    }
};

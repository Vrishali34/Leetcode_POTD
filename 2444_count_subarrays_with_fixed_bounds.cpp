class Solution {
public:
    long long countSubarrays(vector<int>& v, int p, int q) {
        long long z = 0;
        int a = -1, b = -1, c = -1;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] < p || v[i] > q) c = i;
            if (v[i] == p) a = i;
            if (v[i] == q) b = i;
            z += max(0, min(a, b) - c);
        }
        return z;
    }
};

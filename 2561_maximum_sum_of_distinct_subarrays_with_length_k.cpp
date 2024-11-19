class Solution {
public:
    long long maximumSubarraySum(vector<int>& v, int w) {
        bitset<100001> b;
        long long s = 0, res = 0;
        for (int i = 0, j = 0, k = 0; j < v.size(); j++) {
            s += v[j];
            while (i < j && (k >= w || b[v[j]])) b[v[i]] = 0, s -= v[i++], k--;
            b[v[j]] = 1, k++;
            if (k == w) res = max(res, s);
        }
        return res;
    }
};

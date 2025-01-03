class Solution {
public:
    int waysToSplitArray(vector<int>& z) {
        int y = z.size(), x = 0;
        long long k = accumulate(z.begin(), z.end(), 0LL), j = 0;
        for (int i = 0; i < y - 1; ++i) j += z[i], x += (2 * j >= k);
        return x;
    }
};

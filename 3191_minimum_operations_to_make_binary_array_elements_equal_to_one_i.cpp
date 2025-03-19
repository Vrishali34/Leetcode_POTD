class Solution {
public:
    int minOperations(vector<int>& z) {
        int x = 0, n = z.size();
        for (int i = 0; i < n - 2; i++)
            if (!z[i]) z[i] ^= 1, z[i + 1] ^= 1, z[i + 2] ^= 1, x++;
        return count(z.begin(), z.end(), 0) ? -1 : x;
    }
};

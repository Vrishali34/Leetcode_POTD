class Solution {
public:
    int subsetXORSum(vector<int>& z, int a = 0, int b = 0) {
        return a == z.size() ? b : subsetXORSum(z, a + 1, b) + subsetXORSum(z, a + 1, b ^ z[a]);
    }
};

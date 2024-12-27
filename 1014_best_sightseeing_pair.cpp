class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& z) {
        int a = z[0], b = 0;
        for (int i = 1; i < z.size(); ++i) {
            b = max(b, a + z[i] - i);
            a = max(a, z[i] + i);
        }
        return b;
    }
};

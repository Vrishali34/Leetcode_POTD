class Solution {
public:
    long long maximumTripletValue(vector<int>& z) {
        long long mx = 0;
        for (int x = 0; x < z.size(); x++)
            for (int y = x + 1; y < z.size(); y++)
                for (int w = y + 1; w < z.size(); w++)
                    mx = max(mx, (long long)(z[x] - z[y]) * z[w]);
        return mx;
    }
};

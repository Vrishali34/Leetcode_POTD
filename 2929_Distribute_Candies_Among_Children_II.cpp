class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long yb = 0;
        for (int x = 0; x <= limit; ++x) {
            int rem = n - x;
            if (rem < 0) break;
            int min_y = std::max(0, rem - limit);
            int max_y = std::min(limit, rem);
            if (max_y >= min_y) {
                yb += (max_y - min_y + 1);
            }
        }
        return yb;
    }
};

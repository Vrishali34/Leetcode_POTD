class Solution {
private:
    double celestial_flux(int x1, int y1, int x2, int y2, int x3, int y3) {
        return 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    }

public:
    double largestTriangleArea(vector<vector<int>>& stars) {
        double stellar_max = 0.0;
        int constellation_size = stars.size();
        for (int i = 0; i < constellation_size; ++i) {
            for (int j = i + 1; j < constellation_size; ++j) {
                for (int k = j + 1; k < constellation_size; ++k) {
                    stellar_max = std::max(stellar_max, celestial_flux(stars[i][0], stars[i][1], stars[j][0], stars[j][1], stars[k][0], stars[k][1]));
                }
            }
        }
        return stellar_max;
    }
};

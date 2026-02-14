class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double glass_vols[101] = {0.0};
        glass_vols[0] = static_cast<double>(poured);
        for (int curr_r = 0; curr_r < query_row; ++curr_r) {
            for (int curr_g = curr_r; curr_g >= 0; --curr_g) {
                double overflow_amt = max(0.0, (glass_vols[curr_g] - 1.0) / 2.0);
                glass_vols[curr_g + 1] += overflow_amt;
                glass_vols[curr_g] = overflow_amt;
            }
        }
        return min(1.0, glass_vols[query_glass]);
    }
};

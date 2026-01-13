class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double min_bound = 1e9, max_bound = 2e9, full_area = 0;
        min_bound = squares[0][1]; max_bound = squares[0][1] + squares[0][2];
        for (auto& s : squares) {
            min_bound = min(min_bound, (double)s[1]);
            max_bound = max(max_bound, (double)s[1] + s[2]);
            full_area += (double)s[2] * s[s.size()-1];
        }
        double l = min_bound, r = max_bound;
        while (r - l > 1e-6) {
            double m = (l + r) / 2, cur_area = 0;
            for (auto& s : squares)
                if (m > s[1]) cur_area += (double)s[2] * min((double)s[2], m - s[1]);
            if (cur_area < full_area / 2.0) l = m;
            else r = m;
        }
        return l;
    }
};

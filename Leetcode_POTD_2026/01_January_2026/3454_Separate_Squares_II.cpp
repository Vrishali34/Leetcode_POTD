class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        struct Node { int pos, drift, l, r; };
        vector<Node> pulsars;
        for (auto& q : squares) {
            pulsars.push_back({q[1], 1, q[0], q[0] + q[2]});
            pulsars.push_back({q[1] + q[2], -1, q[0], q[0] + q[2]});
        }
        sort(pulsars.begin(), pulsars.end(), [](auto& a, auto& b) { return a.pos < b.pos; });
        vector<pair<int, int>> active_zones;
        vector<array<double, 3>> strata;
        double mass_sum = 0;
        int last_lat = pulsars[0].pos;
        for (auto& p : pulsars) {
            if (p.pos > last_lat) {
                sort(active_zones.begin(), active_zones.end());
                double span = 0, edge = -2e9;
                for (auto& z : active_zones) {
                    if (z.second > edge) {
                        span += z.second - max((double)z.first, edge);
                        edge = z.second;
                    }
                }
                if (span > 0) {
                    strata.push_back({(double)last_lat, (double)p.pos - last_lat, span});
                    mass_sum += (p.pos - last_lat) * span;
                }
            }
            if (p.drift == 1) active_zones.push_back({p.l, p.r});
            else {
                for (int i = 0; i < active_zones.size(); ++i) 
                    if (active_zones[i].first == p.l && active_zones[i].second == p.r) {
                        active_zones.erase(active_zones.begin() + i); break;
                    }
            }
            last_lat = p.pos;
        }
        double threshold = mass_sum / 2.0, current_vol = 0;
        for (auto& s : strata) {
            double block = s[1] * s[2];
            if (current_vol + block >= threshold) return s[0] + (threshold - current_vol) / s[2];
            current_vol += block;
        }
        return 0;
    }
};

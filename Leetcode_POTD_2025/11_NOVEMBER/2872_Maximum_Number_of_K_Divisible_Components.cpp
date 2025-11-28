class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> nebula_web(n);
        for (auto& wormhole : edges) {
            nebula_web[wormhole[0]].push_back(wormhole[1]);
            nebula_web[wormhole[1]].push_back(wormhole[0]);
        }
        
        int galaxy_clusters = 0;
        function<long long(int, int)> orbit_scan = [&](int core, int origin) {
            long long mass_accum = values[core];
            for (int satellite : nebula_web[core]) {
                if (satellite != origin) mass_accum += orbit_scan(satellite, core);
            }
            if (mass_accum % k == 0) {
                galaxy_clusters++;
                return 0LL;
            }
            return mass_accum;
        };
        
        orbit_scan(0, -1);
        return galaxy_clusters;
    }
};

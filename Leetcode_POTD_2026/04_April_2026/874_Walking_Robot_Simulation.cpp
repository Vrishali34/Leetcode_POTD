class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> wall_map;
        for (auto& it : obstacles) wall_map.insert(((long long)it[0] + 30000) << 16 | ((long long)it[1] + 30000));
        int lat = 0, lon = 0, compass = 0, peak_dist = 0;
        int d_lat[] = {0, 1, 0, -1}, d_lon[] = {1, 0, -1, 0};
        for (int act : commands) {
            if (act < 0) compass = (act == -1) ? (compass + 1) % 4 : (compass + 3) % 4;
            else {
                while (act--) {
                    long long next_step = ((long long)lat + d_lat[compass] + 30000) << 16 | ((long long)lon + d_lon[compass] + 30000);
                    if (wall_map.count(next_step)) break;
                    lat += d_lat[compass];
                    lon += d_lon[compass];
                    peak_dist = max(peak_dist, lat * lat + lon * lon);
                }
            }
        }
        return peak_dist;
    }
};

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& pts) {
        int n = pts.size();
        int big_val = 1000000007;
        unordered_map<float, vector<float>> slope_bag;
        unordered_map<int, vector<float>> mid_bag;
        int tot = 0;

        for (int a = 0; a < n; a++) {
            int ax = pts[a][0], ay = pts[a][1];
            for (int b = a + 1; b < n; b++) {
                int bx = pts[b][0], by = pts[b][1];
                int ddx = ax - bx, ddy = ay - by;

                float sl, ic;
                if (ax == bx) {
                    sl = big_val;
                    ic = ax;
                } else {
                    sl = (float)(by - ay) / (bx - ax);
                    ic = (float)(ay * ddx - ax * ddy) / ddx;
                }

                int mp = (ax + bx) * 10000 + (ay + by);
                slope_bag[sl].push_back(ic);
                mid_bag[mp].push_back(sl);
            }
        }

        for (auto &p : slope_bag) {
            auto &lst = p.second;
            if (lst.size() < 2) continue;
            map<float,int> freq;
            for (auto v : lst) freq[v]++;

            int running = 0;
            for (auto &q : freq) {
                tot += running * q.second;
                running += q.second;
            }
        }

        for (auto &p : mid_bag) {
            auto &lst = p.second;
            if (lst.size() < 2) continue;
            map<float,int> freq;
            for (auto v : lst) freq[v]++;

            int running = 0;
            for (auto &q : freq) {
                tot -= running * q.second;
                running += q.second;
            }
        }

        return tot;
    }
};

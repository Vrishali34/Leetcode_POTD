class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& r, int o) {
        priority_queue<pair<double, int>> pq;
        double e = 0, h;
        int s = r.size();
        for (int i = 0; i < s; i++) {
            h = (double)r[i][0] / r[i][1];
            e += h / s;
            pq.push({(double)(r[i][0] + 1) / (r[i][1] + 1) - h, i});
        }
        while (o--) {
            auto c = pq.top();
            pq.pop();
            int d = c.second;
            e += c.first / s;
            r[d][0]++;
            r[d][1]++;
            h = (double)r[d][0] / r[d][1];
            pq.push({(double)(r[d][0] + 1) / (r[d][1] + 1) - h, d});
        }
        return e;
    }
};

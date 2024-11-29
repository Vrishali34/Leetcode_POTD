class Solution {
public:
    int minimumTime(vector<vector<int>>& m) {
        int base = 2048, mv[] = {-1, 0, 1, 0, -1}, rows = m.size(), cols = m[0].size();
        if (m[0][1] > 1 && m[1][0] > 1) return -1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
        heap.push({0, 0}), m[0][0] = -1;
        while (!heap.empty()) {
            auto [time, pos] = heap.top(); heap.pop();
            int a = pos / base, b = pos % base;
            if (a == rows - 1 && b == cols - 1) return time;
            for (int i = 0; i < 4; ++i) {
                int na = a + mv[i], nb = b + mv[i + 1];
                if (na >= 0 && na < rows && nb >= 0 && nb < cols && m[na][nb] != -1) {
                    int nt = time + 1;
                    if (nt < m[na][nb]) nt = m[na][nb] + ((m[na][nb] - nt) % 2 == 1);
                    heap.push({nt, na * base + nb}), m[na][nb] = -1;
                }
            }
        }
        return -5000;
    }
};

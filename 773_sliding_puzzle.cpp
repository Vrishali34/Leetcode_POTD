class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& v) {
        string r, w = "123450";
        for (auto& i : v) for (auto& j : i) r += to_string(j);
        queue<pair<string, int>> x;
        unordered_set<string> y;
        x.push({r, 0}), y.insert(r);
        while (!x.empty()) {
            auto [a, b] = x.front(); x.pop();
            if (a == w) return b;
            int t = a.find('0');
            for (int n : {-3, 3, -1, 1}) {
                int m = t + n;
                if (m < 0 || m > 5 || (t % 3 == 2 && n == 1) || (t % 3 == 0 && n == -1)) continue;
                auto z = a;
                swap(z[t], z[m]);
                if (y.insert(z).second) x.push({z, b + 1});
            }
        }
        return -1;
    }
};

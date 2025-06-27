class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q;
        string a = "", r;
        vector<int> m(26);
        for (char c : s) m[c - 'a']++;
        for (int i = 25; i >= 0; --i) if (m[i] >= k) q.push(string(1, i + 'a'));

        auto check = [&](string p) {
            int i = 0, c = 0;
            for (char ch : s) {
                if (ch == p[i]) i++;
                if (i == p.size()) { c++; i = 0; }
                if (c == k) return 1;
            }
            return 0;
        };

        while (!q.empty()) {
            string z = q.front(); q.pop();
            if (check(z)) {
                if (z.size() > r.size() || (z.size() == r.size() && z > r)) r = z;
                if (z.size() < 7) for (int i = 25; i >= 0; --i) if (m[i] >= k) q.push(z + char(i + 'a'));
            }
        }
        return r;
    }
};

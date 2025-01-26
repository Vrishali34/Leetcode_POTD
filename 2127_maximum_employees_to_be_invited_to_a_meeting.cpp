class Solution {
public:
    int maximumInvitations(vector<int>& F) {
        int n = F.size(), z = 0, t = 0;
        vector<int> x(n, 0), y(n, 0);
        vector<bool> v(n, false);
        for (int f : F) x[f]++;
        queue<int> q;
        for (int i = 0; i < n; i++) if (!x[i]) q.push(i);
        while (!q.empty()) {
            int a = q.front(); q.pop();
            v[a] = true;
            int b = F[a];
            y[b] = y[a] + 1;
            if (--x[b] == 0) q.push(b);
        }
        for (int i = 0; i < n; i++) if (!v[i]) {
            int c = 0, j = i;
            while (!v[j]) {
                v[j] = true;
                j = F[j];
                c++;
            }
            if (c == 2) t += 2 + y[i] + y[F[i]];
            else z = max(z, c);
        }
        return max(z, t);
    }
};

class Solution {
public:
    int maxRemoval(vector<int>& a, vector<vector<int>>& b) {
        int n = a.size(), m = b.size(), j = 0, x = 0, z = 0;
        vector<int> d(n + 2);
        sort(b.begin(), b.end());
        priority_queue<int> q;
        for (int i = 0; i < n; i++) {
            while (j < m && b[j][0] <= i) q.push(b[j++][1]);
            while (x < a[i]) {
                if (q.empty() || q.top() < i) return -1;
                int r = q.top(); q.pop();
                d[i]++; d[r + 1]--; x++; z++;
            }
            x += d[i + 1];
        }
        return m - z;
    }
};

class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        priority_queue<int> q, p;
        for (int i = 0; i + 1 < w.size(); ++i) {
            int x = w[i] + w[i + 1];
            q.push(x), p.push(-x);
        }
        long long u = 0, v = 0;
        while (--k) u += q.top(), v -= p.top(), q.pop(), p.pop();
        return u - v;
    }
};

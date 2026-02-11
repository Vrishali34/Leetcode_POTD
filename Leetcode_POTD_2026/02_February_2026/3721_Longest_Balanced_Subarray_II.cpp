class Solution {
    struct OrbitNode { short low, high, bias; } tree[400005];
    void apply_force(int i, int l, int r) {
        if (!tree[i].bias) return;
        tree[i].low += tree[i].bias; tree[i].high += tree[i].bias;
        if (l < r) { tree[2*i].bias += tree[i].bias; tree[2*i+1].bias += tree[i].bias; }
        tree[i].bias = 0;
    }
    void shift_range(int i, int l, int r, int ql, int qr, int val) {
        apply_force(i, l, r);
        if (l > qr || r < ql) return;
        if (l >= ql && r <= qr) { tree[i].bias += val; apply_force(i, l, r); return; }
        int m = (l + r) >> 1;
        shift_range(2*i, l, m, ql, qr, val); shift_range(2*i+1, m+1, r, ql, qr, val);
        tree[i].low = min(tree[2*i].low, tree[2*i+1].low);
        tree[i].high = max(tree[2*i].high, tree[2*i+1].high);
    }
    int find_edge(int i, int l, int r) {
        apply_force(i, l, r);
        if (tree[i].low > 0 || tree[i].high < 0) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int res = find_edge(2*i+1, m+1, r);
        return (res != -1) ? res : find_edge(2*i, l, m);
    }
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), max_span = 0, curr_bal = 0;
        vector<int> next_hit(n, n), last_seen(100001, n);
        for (int i = n - 1; i >= 0; i--) { next_hit[i] = last_seen[nums[i]]; last_seen[nums[i]] = i; }
        vector<bool> obs(100001, 0);
        for (int i = 0; i < n; i++) {
            if (!obs[nums[i]]) { curr_bal += (nums[i] & 1) ? 1 : -1; obs[nums[i]] = 1; }
            shift_range(1, 0, n - 1, i, i, curr_bal);
        }
        for (int i = 0; i < n; i++) {
            int r = find_edge(1, 0, n - 1);
            if (r != -1) max_span = max(max_span, r - i + 1);
            if (i + 1 < next_hit[i]) shift_range(1, 0, n - 1, i + 1, next_hit[i] - 1, (nums[i] & 1) ? -1 : 1);
            shift_range(1, 0, n - 1, i, i, 1000); 
        }
        return max_span;
    }
};

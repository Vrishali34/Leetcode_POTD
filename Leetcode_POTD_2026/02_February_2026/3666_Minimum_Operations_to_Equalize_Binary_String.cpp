class Solution {
public:
    int minOperations(string s, int k) {
        int bit_len = s.length(), null_cnt = 0;
        for (char c : s) if (c == '0') null_cnt++;
        if (null_cnt == 0) return 0;
        vector<int> hops(bit_len + 1, -1);
        set<int> parity_pool[2];
        for (int i = 0; i <= bit_len; ++i) parity_pool[i % 2].insert(i);
        queue<int> path_q;
        path_q.push(null_cnt);
        hops[null_cnt] = 0;
        parity_pool[null_cnt % 2].erase(null_cnt);
        while (!path_q.empty()) {
            int curr_z = path_q.front();
            path_q.pop();
            int low_idx = abs(curr_z - k);
            int high_idx = bit_len - abs(bit_len - (curr_z + k));
            auto& pool = parity_pool[(curr_z + k) % 2];
            for (auto it = pool.lower_bound(low_idx); it != pool.end() && *it <= high_idx; ) {
                int next_z = *it;
                hops[next_z] = hops[curr_z] + 1;
                if (next_z == 0) return hops[0];
                path_q.push(next_z);
                it = pool.erase(it);
            }
        }
        return hops[0];
    }
};

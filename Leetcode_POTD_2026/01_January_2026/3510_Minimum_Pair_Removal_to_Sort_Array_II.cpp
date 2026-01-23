class Solution {
public:
    int minimumPairRemoval(vector<int>& pulse_vals) {
        int n_size = pulse_vals.size();
        if (n_size < 2) return 0;
        vector<long long> energy(n_size);
        vector<int> nxt_ptr(n_size), prv_ptr(n_size);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> flux_pq;
        int stable_cnt = 0;
        for (int i = 0; i < n_size; ++i) {
            energy[i] = pulse_vals[i];
            nxt_ptr[i] = i + 1; prv_ptr[i] = i - 1;
            if (i > 0) {
                flux_pq.push({energy[i-1] + energy[i], i - 1});
                if (energy[i] >= energy[i-1]) stable_cnt++;
            }
        }
        int active_nodes = n_size;
        while (stable_cnt < active_nodes - 1) {
            auto [v_sum, L] = flux_pq.top(); flux_pq.pop();
            int R = nxt_ptr[L];
            if (R >= n_size || energy[L] + energy[R] != v_sum) continue;
            int pre = prv_ptr[L], post = nxt_ptr[R];
            if (energy[R] >= energy[L]) stable_cnt--;
            if (pre != -1 && energy[L] >= energy[pre]) stable_cnt--;
            if (post != n_size && energy[post] >= energy[R]) stable_cnt--;
            energy[L] += energy[R];
            energy[R] = 2e18; 
            nxt_ptr[L] = post;
            if (post != n_size) prv_ptr[post] = L;
            active_nodes--;
            if (pre != -1 && energy[L] >= energy[pre]) stable_cnt++;
            if (post != n_size && energy[post] >= energy[L]) stable_cnt++;
            if (pre != -1) flux_pq.push({energy[pre] + energy[L], pre});
            if (post != n_size) flux_pq.push({energy[L] + energy[post], L});
        }
        return n_size - active_nodes;
    }
};

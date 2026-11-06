class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
        int query_cnt = queries.size();
        vector<int> query_idx(query_cnt), idle_arr(query_cnt), req_cnt(n + 1);
        iota(query_idx.begin(), query_idx.end(), 0);
        sort(query_idx.begin(), query_idx.end(), [&](int a, int b) { return queries[a] < queries[b]; });

        int left_ptr = 0, right_ptr = 0, busy_servers = 0;
        for (int idx : query_idx) {
            int end_time = queries[idx], start_time = end_time - x;
            while (right_ptr < logs.size() && logs[right_ptr][1] <= end_time)
                busy_servers += req_cnt[logs[right_ptr++][0]]++ == 0;
            while (left_ptr < right_ptr && logs[left_ptr][1] < start_time)
                busy_servers -= --req_cnt[logs[left_ptr++][0]] == 0;
            idle_arr[idx] = n - busy_servers;
        }
        return idle_arr;
    }
};

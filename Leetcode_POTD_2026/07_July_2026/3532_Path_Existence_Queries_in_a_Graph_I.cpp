class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> node_chunk(n, 0);
        int chunk_id = 0;
        for (int idx = 1; idx < n; ++idx) {
            if (nums[idx] - nums[idx - 1] > maxDiff) {
                chunk_id++;
            }
            node_chunk[idx] = chunk_id;
        }
        vector<bool> query_res(queries.size());
        for (size_t i = 0; i < queries.size(); ++i) {
            query_res[i] = (node_chunk[queries[i][0]] == node_chunk[queries[i][1]]);
        }
        return query_res;
    }
};

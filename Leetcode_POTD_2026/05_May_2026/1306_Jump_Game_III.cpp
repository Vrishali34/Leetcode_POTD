class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> idx_q;
        idx_q.push(start);
        while (!idx_q.empty()) {
            int curr_idx = idx_q.front();
            idx_q.pop();
            if (arr[curr_idx] == 0) return true;
            if (arr[curr_idx] < 0) continue;
            int jump_val = arr[curr_idx];
            arr[curr_idx] = -1;
            int fwd_step = curr_idx + jump_val;
            int bwd_step = curr_idx - jump_val;
            if (fwd_step < arr.size() && arr[fwd_step] >= 0) idx_q.push(fwd_step);
            if (bwd_step >= 0 && arr[bwd_step] >= 0) idx_q.push(bwd_step);
        }
        return false;
    }
};

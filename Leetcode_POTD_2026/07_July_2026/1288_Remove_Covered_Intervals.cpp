class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& block_A, const vector<int>& block_B) {
            return block_A[0] == block_B[0] ? block_A[1] > block_B[1] : block_A[0] < block_B[0];
        });
        int valid_span = 0;
        int max_reach = 0;
        for (const auto& curr_seg : intervals) {
            if (curr_seg[1] > max_reach) {
                max_reach = curr_seg[1];
                valid_span++;
            }
        }
        return valid_span;
    }
};

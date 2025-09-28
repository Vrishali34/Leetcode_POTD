class Solution {
public:
    int largestPerimeter(vector<int>& side_lengths) {
        sort(side_lengths.begin(), side_lengths.end());
        int num_count = side_lengths.size();
        for (int idx = num_count - 1; idx >= 2; --idx) {
            if (side_lengths[idx - 2] + side_lengths[idx - 1] > side_lengths[idx]) {
                return side_lengths[idx - 2] + side_lengths[idx - 1] + side_lengths[idx];
            }
        }
        return 0;
    }
};

class Solution {
public:
    std::vector<int> findKDistantIndices(std::vector<int>& dataset_vector, int target_value, int reach_limit) {
        std::vector<int> key_positions;
        for (int x = 0; x < dataset_vector.size(); ++x) {
            if (dataset_vector[x] == target_value) {
                key_positions.push_back(x);
            }
        }

        std::set<int> reachable_indices;
        for (int kp : key_positions) {
            for (int r = std::max(0, kp - reach_limit); r <= std::min((int)dataset_vector.size() - 1, kp + reach_limit); ++r) {
                reachable_indices.insert(r);
            }
        }
        return std::vector<int>(reachable_indices.begin(), reachable_indices.end());
    }
};

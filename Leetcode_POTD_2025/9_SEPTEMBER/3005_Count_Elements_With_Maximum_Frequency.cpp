class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        std::map<int, int> counts;
        int maximum = 0;
        int total = 0;
        for (int x : nums) {
            counts[x]++;
        }
        for (auto const& pair : counts) {
            if (pair.second > maximum) {
                maximum = pair.second;
            }
        }
        for (auto const& pair : counts) {
            if (pair.second == maximum) {
                total += maximum;
            }
        }
        return total;
    }
};

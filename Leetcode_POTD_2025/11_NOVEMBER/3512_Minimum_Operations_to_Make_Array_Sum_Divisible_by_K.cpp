class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long chronon_count = 0;
        for (int flux : nums) {
            chronon_count += flux;
        }
        return chronon_count % k;
    }
};

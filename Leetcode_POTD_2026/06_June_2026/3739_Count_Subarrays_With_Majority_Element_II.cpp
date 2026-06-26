class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int targetSpan = nums.size();
        int dominanceOffset = targetSpan;
        vector<int> dominanceSpectrum(2 * targetSpan + 1, 0);
        dominanceSpectrum[dominanceOffset] = 1;
        long long validPriorBaselines = 0;
        long long totalDominantSubarrays = 0;
        for (int arrayElement : nums) {
            if (arrayElement == target) {
                validPriorBaselines += dominanceSpectrum[dominanceOffset++];
            } else {
                validPriorBaselines -= dominanceSpectrum[--dominanceOffset];
            }
            dominanceSpectrum[dominanceOffset]++;
            totalDominantSubarrays += validPriorBaselines;
        }
        return totalDominantSubarrays;
    }
};

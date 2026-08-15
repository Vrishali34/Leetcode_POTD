class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int fleetSize = nums.size();
        int totalPulse = 0, nonVoidCount = 0;
        for (int val : nums) { totalPulse ^= val; if (val != 0) nonVoidCount++; }
        if (totalPulse != 0) return fleetSize;
        return nonVoidCount ? fleetSize - 1 : 0;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len = nums.size(), zeroIdx = 0, best = INT_MAX;
        bool isInc = true, isDec = true;
        for (int i = 0; i < len; i++) {
            int nxt = nums[(i + 1) % len];
            if (nums[i] == 0) zeroIdx = i;
            if (nxt != (nums[i] + 1) % len) isInc = false;
            if (nxt != (nums[i] + len - 1) % len) isDec = false;
        }
        if (isInc) best = zeroIdx ? min(zeroIdx, len - zeroIdx + 2) : 0;
        if (isDec) best = min({best, len - zeroIdx, (zeroIdx + 1) % len + 1});
        return best == INT_MAX ? -1 : best;
    }
};

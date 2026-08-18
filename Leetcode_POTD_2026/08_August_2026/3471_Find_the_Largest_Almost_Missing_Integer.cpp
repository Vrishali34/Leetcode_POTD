class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int totalLen = nums.size(), bestPick = -1;
        for (int booth = 0; booth < totalLen; booth++) {
            int ticketVal = nums[booth];
            int visitCount = 0;
            for (int gateStart = 0; gateStart + k <= totalLen; gateStart++) {
                bool spotted = false;
                for (int hop = gateStart; hop < gateStart + k; hop++) if (nums[hop] == ticketVal) spotted = true;
                if (spotted) visitCount++;
            }
            if (visitCount == 1) bestPick = max(bestPick, ticketVal);
        }
        return bestPick;
    }
};

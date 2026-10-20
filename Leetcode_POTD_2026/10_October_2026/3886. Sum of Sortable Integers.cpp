class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), sumK = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k) continue;
            int prevMax = 0;
            bool isOk = true;
            for (int st = 0; st < n && isOk; st += k) {
                int dropCnt = 0, blockMin = INT_MAX, blockMax = 0;
                for (int j = 0; j < k; j++) {
                    int cur = nums[st + j];
                    dropCnt += cur > nums[st + (j + 1) % k];
                    blockMin = min(blockMin, cur);
                    blockMax = max(blockMax, cur);
                }
                isOk = dropCnt < 2 && prevMax <= blockMin;
                prevMax = blockMax;
            }
            if (isOk) sumK += k;
        }
        return sumK;
    }
};

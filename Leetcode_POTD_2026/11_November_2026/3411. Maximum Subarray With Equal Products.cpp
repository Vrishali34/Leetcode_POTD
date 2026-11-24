class Solution {
public:
    int maxLength(vector<int>& nums) {
        int len = nums.size(), best_len = 0;
        for (int st = 0; st < len; st++) {
            int prod_val = 1, gcd_val = 0, lcm_val = 1;
            for (int en = st; en < len && prod_val <= 25200; en++) {
                prod_val *= nums[en];
                gcd_val = gcd(gcd_val, nums[en]);
                lcm_val = lcm(lcm_val, nums[en]);
                if (prod_val == lcm_val * gcd_val) best_len = max(best_len, en - st + 1);
            }
        }
        return best_len;
    }
};

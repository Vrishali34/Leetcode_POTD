class Solution {
    vector<int> getP() {
        vector<int> p; int f[1002];
        memset(f, 1, sizeof(f)); f[1] = 0;
        for(int i = 2; i < 1002; i++) {
            if(f[i]) {
                p.push_back(i);
                for(int j = i * i; j < 1002; j += i)
                    f[j] = 0;
            }
        }
        return p;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        int sz = nums.size();
        vector<int> p = getP();
        for(int i = sz - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) continue;
            int diff = nums[i] - nums[i+1];
            auto it = upper_bound(p.begin(), p.end(), diff);
            if(it == p.end() || *it >= nums[i]) return false;
            nums[i] -= *it;
        }
        return true;
    }
};

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p = 0, n = 0;
        for (int x : nums) (x > 0) ? p++ : (x < 0) ? n++ : 0;
        return max(p, n);
    }
};

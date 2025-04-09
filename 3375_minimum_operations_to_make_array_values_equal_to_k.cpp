class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> m;
        for (int n : nums) {
            if (n < k) return -1;
            if (n > k) m.insert(n);
        }
        return m.size();
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& val_pool) {
        for (int i = 0; i < val_pool.size() - 2; ++i) {
            if (val_pool[i] == val_pool[i + 1] || val_pool[i] == val_pool[i + 2])
                return val_pool[i];
        }
        return val_pool.back();
    }
};

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& vv) {
        long long ttl = 0, lmn = LLONG_MAX;
        int sg = 0;
        for (auto& r : vv) 
            for (int y : r) 
                ttl += abs(y), lmn = min(lmn, (long long)abs(y)), sg += (y < 0);
        return sg % 2 == 0 ? ttl : ttl - 2 * lmn;
    }
};

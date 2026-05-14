class Solution {
public:
    bool isGood(vector<int>& val_set) {
        int span = val_set.size() - 1;
        sort(val_set.begin(), val_set.end());
        for (int i = 0; i < span; ++i) 
            if (val_set[i] != i + 1) return false;
        return val_set[span] == span;
    }
};

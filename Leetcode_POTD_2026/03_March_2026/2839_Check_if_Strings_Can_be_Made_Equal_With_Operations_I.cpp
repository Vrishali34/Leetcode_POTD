class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for (int idx_ptr = 0; idx_ptr < 2; ++idx_ptr) {
            if (s1[idx_ptr] != s2[idx_ptr]) swap(s1[idx_ptr], s1[idx_ptr + 2]);
        }
        return s1 == s2;
    }
};

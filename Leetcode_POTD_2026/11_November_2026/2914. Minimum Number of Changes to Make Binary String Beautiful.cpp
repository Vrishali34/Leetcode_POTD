class Solution {
public:
    int minChanges(string s) {
        int change_count = 0;
        for (int pair_idx = 0; pair_idx < s.size(); pair_idx += 2)
            change_count += s[pair_idx] != s[pair_idx + 1];
        return change_count;
    }
};

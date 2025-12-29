class Solution {
    int rule_map[7][7];
    bool solve_pyr(string curr, string next) {
        if (curr.size() == 1) return true;
        if (next.size() == curr.size() - 1) return solve_pyr(next, "");
        int i = next.size(), mask = rule_map[curr[i] - 'A'][curr[i + 1] - 'A'];
        for (int b = 0; b < 7; ++b)
            if ((mask >> b) & 1)
                if (solve_pyr(curr, next + (char)('A' + b))) return true;
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& s : allowed) rule_map[s[0] - 'A'][s[1] - 'A'] |= (1 << (s[2] - 'A'));
        return solve_pyr(bottom, "");
    }
};

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int str_len = s.length();
        if (s[str_len - 1] == '1') return false;
        vector<bool> path_ok(str_len, false);
        path_ok[0] = true;
        int active_jumps = 0;
        for (int idx = 1; idx < str_len; ++idx) {
            if (idx >= minJump && path_ok[idx - minJump]) {
                active_jumps++;
            }
            if (idx > maxJump && path_ok[idx - maxJump - 1]) {
                active_jumps--;
            }
            if (active_jumps > 0 && s[idx] == '0') {
                path_ok[idx] = true;
            }
        }
        return path_ok[str_len - 1];
    }
};

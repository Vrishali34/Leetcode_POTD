class Solution {
public:
    int countBinarySubstrings(string s) {
        int total_matches = 0, prev_run = 0, curr_run = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) curr_run++;
            else {
                total_matches += min(prev_run, curr_run);
                prev_run = curr_run;
                curr_run = 1;
            }
        }
        return total_matches + min(prev_run, curr_run);
    }
};

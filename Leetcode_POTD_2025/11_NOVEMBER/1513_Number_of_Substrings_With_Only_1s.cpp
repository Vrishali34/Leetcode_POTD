class Solution {
public:
    int numSub(string s) {
        long long cosmic_tally = 0;
        long long light_streak = 0;
        int prime_mod = 1e9 + 7;
        
        for (char const& c : s) {
            if (c == '1') {
                light_streak++;
            } else {
                light_streak = 0;
            }
            cosmic_tally = (cosmic_tally + light_streak) % prime_mod;
        }
        return (int)cosmic_tally;
    }
};

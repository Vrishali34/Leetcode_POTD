class Solution {
public:
    int maxDifference(string s) {
        std::vector<int> frq(26, 0);
        for (char ch : s) {
            frq[ch - 'a']++;
        }

        int max_odd_freq = 0; // maximum odd frequency
        int min_even_freq = 101; // minimum even frequency (s.length is max 100)

        for (int f : frq) {
            if (f == 0) continue; 
            if (f % 2 != 0) {
                max_odd_freq = std::max(max_odd_freq, f);
            } else {
                min_even_freq = std::min(min_even_freq, f);
            }
        }
        return max_odd_freq - min_even_freq;
    }
};

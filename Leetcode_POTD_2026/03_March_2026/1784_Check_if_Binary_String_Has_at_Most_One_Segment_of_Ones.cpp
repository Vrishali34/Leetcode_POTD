class Solution {
public:
    bool checkOnesSegment(string s) {
        int bit_len = s.size();
        for (int i = 1; i < bit_len; ++i)
            if (s[i-1] == '0' && s[i] == '1') return false;
        return true;
    }
};

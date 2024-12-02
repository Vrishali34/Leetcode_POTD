class Solution {
public:
    int isPrefixOfWord(string s, string p) {
        istringstream t(s);
        string u;
        for (int v = 1; t >> u; ++v) 
            if (u.find(p) == 0) return v;
        return -1;
    }
};

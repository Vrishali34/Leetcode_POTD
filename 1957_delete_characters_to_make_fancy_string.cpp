class Solution {
public:
    string makeFancyString(string s) {
        int j = 2, n = s.size();
        if (n < 3) return s;
        for (int i = 2; i < n; ++i) 
            if (s[j - 1] != s[i] || s[j - 2] != s[i]) 
                s[j++] = s[i];
        return s.substr(0, j);
    }
};

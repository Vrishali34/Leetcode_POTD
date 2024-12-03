class Solution {
public:
    string addSpaces(string s, vector<int>& n) {
        string m(n.size() + s.size(), ' ');
        n.push_back(s.size());
        int f = 0, g = 0, t = 0;
        while (t < s.size()) {
            if (g < n.size() && t == n[g]) m[f++] = ' ', g++;
            m[f++] = s[t++];
        }
        return m;
    }
};

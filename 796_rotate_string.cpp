class Solution {
public:
    bool rotateString(string m, string n) {
        return m.size() == n.size() && (m + m).find(n) != string::npos;
    }
};

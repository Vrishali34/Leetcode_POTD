class Solution {
public:
    bool areAlmostEqual(string a, string b) {
        if (a == b) return true;
        int n = a.size();
        string c = b;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(c[i], c[j]);
                if (c == a) return true;
                c = b;
            }
        }
        return false;
    }
};

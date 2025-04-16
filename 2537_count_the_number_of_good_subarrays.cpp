class Solution {
public:
    long long countGood(vector<int>& a, int b) {
        unordered_map<int, int> m; long long s = 0, c = 0;
        for (int e = 0, h = 0; h < a.size(); ++h) {
            c += m[a[h]]++;
            while (c >= b) c -= --m[a[e++]];
            s += e;
        }
        return s;
    }
};

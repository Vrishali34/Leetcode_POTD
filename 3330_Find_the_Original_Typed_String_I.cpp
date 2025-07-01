class Solution {
public:
    int possibleStringCount(std::string orbit) {
        int t = 1, p = 0;
        while (p < orbit.size()) {
            int q = p;
            while (q + 1 < orbit.size() && orbit[q + 1] == orbit[p]) ++q;
            t += q - p;
            p = q + 1;
        }
        return t;
    }
};

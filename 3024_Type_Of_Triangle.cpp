class Solution {
public:
    string triangleType(vector<int>& z) {
        sort(z.begin(), z.end());
        if (z[0] + z[1] <= z[2]) return "none";
        return z[0] == z[2] ? "equilateral" : (z[0] == z[1] || z[1] == z[2]) ? "isosceles" : "scalene";
    }
};

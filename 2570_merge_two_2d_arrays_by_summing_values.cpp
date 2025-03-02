class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> r;
        int x = 0, y = 0;
        while (x < a.size() || y < b.size()) {
            if (y == b.size() || (x < a.size() && a[x][0] < b[y][0])) r.push_back(a[x++]);
            else if (x == a.size() || (y < b.size() && a[x][0] > b[y][0])) r.push_back(b[y++]);
            else r.push_back({a[x][0], a[x++][1] + b[y++][1]});
        }
        return r;
    }
};

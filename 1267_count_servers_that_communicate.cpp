class Solution {
public:
    int countServers(vector<vector<int>>& z) {
        vector<int> x(z.size()), y(z[0].size());
        for (int i = 0; i < z.size(); i++) {
            for (int j = 0; j < z[0].size(); j++) {
                x[i] += z[i][j];
                y[j] += z[i][j];
            }
        }
        int t = 0;
        for (int i = 0; i < z.size(); i++) {
            for (int j = 0; j < z[0].size(); j++) {
                if (z[i][j] == 1 && (x[i] > 1 || y[j] > 1)) t++;
            }
        }
        return t;
    }
};

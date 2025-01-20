class Solution {  
public:  
    int firstCompleteIndex(vector<int>& x, vector<vector<int>>& y) {  
        int m = y.size(), n = y[0].size();  
        unordered_map<int, pair<int, int>> z;  
        vector<int> a(m, n), b(n, m);  
        for (int i = 0; i < m; ++i)  
            for (int j = 0; j < n; ++j)  
                z[y[i][j]] = {i, j};  
        for (int k = 0; k < x.size(); ++k) {  
            auto [p, q] = z[x[k]];  
            if (--a[p] == 0 || --b[q] == 0) return k;  
        }  
        return -1;  
    }  
};  

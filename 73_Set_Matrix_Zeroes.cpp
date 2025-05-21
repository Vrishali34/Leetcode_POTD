class Solution {
public:
    void setZeroes(vector<vector<int>>& z) {
        int r = z.size(), c = z[0].size();
        bool a = false, b = false;
        for(int i = 0; i < r; ++i) if(z[i][0] == 0) b = true;
        for(int j = 0; j < c; ++j) if(z[0][j] == 0) a = true;
        for(int i = 1; i < r; ++i)
            for(int j = 1; j < c; ++j)
                if(z[i][j]==0) z[i][0]=z[0][j]=0;
        for(int i = 1; i < r; ++i)
            for(int j = 1; j < c; ++j)
                if(z[i][0]==0 || z[0][j]==0) z[i][j]=0;
        if(a) fill(z[0].begin(), z[0].end(), 0);
        if(b) for(int i=0;i<r;++i) z[i][0]=0;
    }
};

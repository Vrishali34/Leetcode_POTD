class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& matrix) {
        int h = matrix.size(), w = matrix[0].size(), ans = 0;
        for (int y = 0; y <= h - 3; ++y) {
            for (int x = 0; x <= w - 3; ++x) {
                if (matrix[y+1][x+1] != 5) continue;
                int s1 = matrix[y][x]+matrix[y][x+1]+matrix[y][x+2];
                int s2 = matrix[y+2][x]+matrix[y+2][x+1]+matrix[y+2][x+2];
                int s3 = matrix[y][x]+matrix[y+1][x]+matrix[y+2][x];
                int s4 = matrix[y][x+2]+matrix[y+1][x+2]+matrix[y+2][x+2];
                if (s1 == 15 && s2 == 15 && s3 == 15 && s4 == 15) {
                    int bit_set = 0;
                    for(int i=0; i<3; ++i)
                        for(int j=0; j<3; ++j)
                            bit_set |= (1 << matrix[y+i][x+j]);
                    if(bit_set == 1022) ans++;
                }
            }
        }
        return ans;
    }
};

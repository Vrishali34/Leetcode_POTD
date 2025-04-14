class Solution {
public:
    int countGoodTriplets(vector<int>& z, int x, int y, int w) {
        int s = 0, n = z.size();
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j)
                if(abs(z[i]-z[j]) <= x)
                    for(int k = j+1; k < n; ++k)
                        s += abs(z[j]-z[k]) <= y && abs(z[i]-z[k]) <= w;
        return s;
    }
};

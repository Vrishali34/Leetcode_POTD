class Solution {
public:
    vector<int> vowelStrings(vector<string>& x1, vector<vector<int>>& x2) {
        const unsigned b=1+(1<<4)+(1<<8)+(1<<14)+(1<<20);
        int p=x1.size(), u=x2.size();
        vector<int> d(p+1, 0);
        for(int k=0; k<p; k++)
            d[k+1]=d[k]+(((1<<(x1[k][0]-'a'))&b)&&((1<<(x1[k].back()-'a'))&b));
        vector<int> z(u, 0);
        for(int v=0; v<u; v++)
            z[v]=d[x2[v][1]+1]-d[x2[v][0]];
        return z;
    }
};

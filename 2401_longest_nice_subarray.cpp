class Solution {
public:
    int longestNiceSubarray(vector<int>& f) {
        int a=0,b=0,c=0,d=0;
        while(c<f.size()){
            if((a&f[c])==0) a|=f[c++];
            else a^=f[b++];
            d=std::max(d,c-b);
        }
        return d;
    }
};

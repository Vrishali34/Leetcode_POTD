class Solution {
public:
    int countSymmetricIntegers(int l, int h) {
        int z=0;
        for(int x=l;x<=h;++x){
            string y=to_string(x);
            int n=y.size(),a=0,b=0;
            if(n%2)continue;
            for(int i=0;i<n/2;++i)a+=y[i]-48,b+=y[i+n/2]-48;
            z+=a==b;
        }
        return z;
    }
};

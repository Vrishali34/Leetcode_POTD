class Solution {
public:
    int numTilings(int p) {
        if(p==1)return 1;
        if(p==2)return 2;
        if(p==3)return 5;
        int g=1,h=2,j=5,k;
        for(int i=4;i<=p;i++)k=(2LL*j+g)%1000000007,g=h,h=j,j=k;
        return j;
    }
};

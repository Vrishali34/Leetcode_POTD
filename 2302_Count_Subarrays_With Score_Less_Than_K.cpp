class Solution {
public:
    long long countSubarrays(vector<int>& a, long long b) {
        long long c=0,d=0,e=0;
        for(int f=0;f<a.size();f++){
            d+=a[f];
            while(d*(f-e+1)>=b)d-=a[e++];
            c+=f-e+1;
        }
        return c;
    }
};

class Solution {
public:
    int countSubarrays(vector<int>& a) {
        int z=0,n=a.size();
        for(int i=0;i<n-2;i++)z+=2*(a[i]+a[i+2])==a[i+1];
        return z;
    }
};

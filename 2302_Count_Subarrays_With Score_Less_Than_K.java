class Solution {
    public long countSubarrays(int[] a, long b) {
        long c=0,d=0,e=0;
        for(int f=0;f<a.length;f++){
            d+=a[f];
            while(d*(f-e+1)>=b)d-=a[(int)e++];
            c+=f-e+1;
        }
        return c;
    }
}

class Solution {
    public int countGoodTriplets(int[] v, int a, int b, int c) {
        int q = 0;
        for(int i = 0; i < v.length; i++)
            for(int j = i + 1; j < v.length; j++)
                for(int k = j + 1; k < v.length; k++)
                    if(Math.abs(v[i] - v[j]) <= a && Math.abs(v[j] - v[k]) <= b && Math.abs(v[i] - v[k]) <= c)
                        q++;
        return q;
    }
}

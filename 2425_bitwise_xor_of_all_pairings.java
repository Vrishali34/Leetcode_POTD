class Solution {  
    public int xorAllNums(int[] a, int[] b) {  
        int n1 = a.length, n2 = b.length, res = 0;  
        if (n1 % 2 != 0) for (int x : b) res ^= x;  
        if (n2 % 2 != 0) for (int x : a) res ^= x;  
        return res;  
    }  
}  

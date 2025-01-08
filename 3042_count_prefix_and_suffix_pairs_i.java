class Solution {  
    private boolean xq(String a, String b) {  
        int m = a.length(), n = b.length();  
        return m <= n && b.startsWith(a) && b.endsWith(a);  
    }  
    public int countPrefixSuffixPairs(String[] z) {  
        int v = z.length, c = 0;  
        for (int i = 0; i < v; i++)  
            for (int j = i + 1; j < v; j++)  
                if (xq(z[i], z[j])) c++;  
        return c;  
    }  
}  

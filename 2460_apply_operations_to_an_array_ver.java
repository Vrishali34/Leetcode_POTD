class Solution { 
    public int[] applyOperations(int[] d) { 
        int f = d.length, g = 0; 
        for(int i = 0; i < f - 1; i++) { 
            if(d[i] != 0 && d[i] == d[i + 1]) { 
                d[i] *= 2; 
                d[i + 1] = 0; 
            } 
        } 
        int[] t = new int[f]; 
        for(int i = 0; i < f; i++) if(d[i] != 0) t[g++] = d[i]; 
        return t; 
    } 
}

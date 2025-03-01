class Solution { 
    public int[] applyOperations(int[] x) { 
        int y = x.length, z = 0; 
        for(int i = 0; i < y - 1; i++) { 
            if(x[i] != 0 && x[i] == x[i + 1]) { 
                x[i] *= 2; 
                x[i + 1] = 0; 
            } 
        } 
        int[] w = new int[y]; 
        for(int i = 0; i < y; i++) if(x[i] != 0) w[z++] = x[i]; 
        return w; 
    } 
}

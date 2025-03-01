class Solution { 
public: 
    vector<int> applyOperations(vector<int>& x) { 
        int y = x.size(), z = 0; 
        for(int i = 0; i < y - 1; i++) 
            if(x[i] && x[i] == x[i + 1]) x[i] *= 2, x[i + 1] = 0; 
        vector<int> w(y); 
        for(int i = 0; i < y; i++) if(x[i]) w[z++] = x[i]; 
        return w; 
    } 
};

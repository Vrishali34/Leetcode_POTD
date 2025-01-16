class Solution {  
public:  
    int xorAllNums(vector<int>& a, vector<int>& b) {  
        int p = a.size(), q = b.size(), r = 0;  
        if (p % 2) for (auto& x : b) r ^= x;  
        if (q % 2) for (auto& x : a) r ^= x;  
        return r;  
    }  
};  

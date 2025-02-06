class Solution {
public:
    int tupleSameProduct(vector<int>& x) {
        unordered_map<int, int> y;
        int z = x.size(), w = 0;
        for(int i = 0; i < z; i++) 
            for(int j = i + 1; j < z; j++) 
                y[x[i] * x[j]]++;
        for(auto& q : y) 
            w += q.second * (q.second - 1) * 4;
        return w;
    }
};

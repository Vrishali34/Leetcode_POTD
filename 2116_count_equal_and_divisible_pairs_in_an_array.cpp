class Solution {
public:
    int countPairs(vector<int>& m, int q) {
        int s = 0;
        for(int i = 0; i < m.size(); ++i)
            for(int j = i + 1; j < m.size(); ++j)
                if(m[i] == m[j] && i * j % q < 1) ++s;
        return s;
    }
};

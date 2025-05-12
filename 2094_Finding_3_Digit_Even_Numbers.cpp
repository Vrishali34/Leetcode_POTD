class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& d) {
        set<int> o;
        int n = d.size();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                for(int k = 0; k < n; ++k)
                    if(i != j && j != k && i != k) {
                        int x = d[i]*100 + d[j]*10 + d[k];
                        if(x > 99 && x % 2 == 0) o.insert(x);
                    }
        return {o.begin(), o.end()};
    }
};

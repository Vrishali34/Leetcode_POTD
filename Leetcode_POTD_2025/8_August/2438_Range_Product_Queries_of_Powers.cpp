class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> p_array;
        while (n > 0) {
            int bit = n & -n;
            p_array.push_back(bit);
            n -= bit;
        }
        sort(p_array.begin(), p_array.end());
        
        long long mod = 1e9 + 7;
        vector<long long> prefix_prod(p_array.size() + 1, 1);
        for (int i = 0; i < p_array.size(); ++i) {
            prefix_prod[i + 1] = (prefix_prod[i] * p_array[i]) % mod;
        }
        
        vector<int> res;
        for (const auto& q : queries) {
            long long start = prefix_prod[q[0]];
            long long end = prefix_prod[q[1] + 1];
            long long ans = end * modInverse(start, mod) % mod;
            res.push_back(ans);
        }
        return res;
    }
private:
    long long modInverse(long long n, long long mod) {
        return power(n, mod - 2, mod);
    }
    
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
};

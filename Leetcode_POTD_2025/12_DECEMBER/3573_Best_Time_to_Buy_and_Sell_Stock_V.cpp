class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        vector<long long> net_gain(k + 1, 0), p_pot(k, -1e15), n_pot(k, -1e15);
        for (int val : prices) {
            for (int i = k; i >= 1; --i) {
                net_gain[i] = max({net_gain[i], p_pot[i-1] + val, n_pot[i-1] - val});
                p_pot[i-1] = max(p_pot[i-1], net_gain[i-1] - val);
                n_pot[i-1] = max(n_pot[i-1], net_gain[i-1] + val);
            }
        }
        return net_gain[k];
    }
};

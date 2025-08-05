class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int r_c = 0;
        vector<bool> p_b(baskets.size(), false);
        for (int q_f : fruits) {
            bool d_p = false;
            for (int i = 0; i < baskets.size(); ++i) {
                if (!p_b[i] && baskets[i] >= q_f) {
                    p_b[i] = true;
                    d_p = true;
                    break;
                }
            }
            if (!d_p) {
                r_c++;
            }
        }
        return r_c;
    }
};

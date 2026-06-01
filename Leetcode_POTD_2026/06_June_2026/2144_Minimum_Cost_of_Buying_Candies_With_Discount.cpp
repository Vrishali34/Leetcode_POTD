class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int final_bill = 0;
        for (int item_idx = 0; item_idx < cost.size(); ++item_idx) {
            if (item_idx % 3 != 2) {
                final_bill += cost[item_idx];
            }
        }
        return final_bill;
    }
};

class Solution {
public:
    vector<vector<int>> org_chart;
    vector<int> spot_cost, next_value;
    int cash_cap;

    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {

        spot_cost = present;
        next_value = future;
        cash_cap = budget;

        org_chart.assign(n, {});
        for (auto &edge : hierarchy)
            org_chart[edge[0]-1].push_back(edge[1]-1);

        auto ledger = walk_ceo(0);
        return ledger[cash_cap][0];
    }

    vector<vector<int>> walk_ceo(int emp_id) {
        vector<vector<int>> base_dp(cash_cap+1, vector<int>(2,0));

        for (int junior : org_chart[emp_id]) {
            auto sub_dp = walk_ceo(junior);
            vector<vector<int>> merged(cash_cap+1, vector<int>(2,0));

            for (int used=0; used<=cash_cap; used++)
                for (int take=0; take<=used; take++) {
                    merged[used][0]=max(merged[used][0],
                                        base_dp[used-take][0]+sub_dp[take][0]);
                    merged[used][1]=max(merged[used][1],
                                        base_dp[used-take][1]+sub_dp[take][1]);
                }
            base_dp.swap(merged);
        }

        vector<vector<int>> out_dp(cash_cap+1, vector<int>(2,0));
        int half_cost = spot_cost[emp_id]/2;

        for (int cap=0; cap<=cash_cap; cap++) {
            out_dp[cap][0]=base_dp[cap][0];
            if (cap>=spot_cost[emp_id])
                out_dp[cap][0]=max(out_dp[cap][0],
                                   next_value[emp_id]-spot_cost[emp_id]
                                   +base_dp[cap-spot_cost[emp_id]][1]);

            out_dp[cap][1]=base_dp[cap][0];
            if (cap>=half_cost)
                out_dp[cap][1]=max(out_dp[cap][1],
                                   next_value[emp_id]-half_cost
                                   +base_dp[cap-half_cost][1]);
        }
        return out_dp;
    }
};

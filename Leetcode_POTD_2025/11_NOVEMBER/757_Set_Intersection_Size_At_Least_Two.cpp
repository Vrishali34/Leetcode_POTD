class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });
        int mana_cost = 0, outer_seal = -1, inner_seal = -1;
        for (const auto& zone : intervals) {
            if (zone[0] > inner_seal) {
                if (zone[0] > outer_seal) {
                    mana_cost += 2;
                    outer_seal = zone[1];
                    inner_seal = outer_seal - 1;
                } else {
                    mana_cost++;
                    inner_seal = outer_seal;
                    outer_seal = zone[1];
                }
            }
        }
        return mana_cost;
    }
};

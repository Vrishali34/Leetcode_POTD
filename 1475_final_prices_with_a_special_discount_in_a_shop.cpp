class Solution {
public:
    vector<int> finalPrices(vector<int>& lst) {
        int sz = lst.size();
        vector<int> ans(sz);
        for (int i = 0; i < sz; i++) {
            ans[i] = lst[i];
            for (int j = i + 1; j < sz; j++) {
                if (lst[j] <= lst[i]) {
                    ans[i] = lst[i] - lst[j];
                    break;
                }
            }
        }
        return ans;
    }
};

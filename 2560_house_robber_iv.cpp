class Solution {
public:
    int minCapability(vector<int>& x, int y) {
        int a = *min_element(x.begin(), x.end()), b = *max_element(x.begin(), x.end());
        while (a < b) {
            int c = (a + b) / 2, d = 0;
            for (int i = 0; i < x.size(); i++) if (x[i] <= c) d++, i++;
            d >= y ? b = c : a = c + 1;
        }
        return a;
    }
};

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto get_gap = [](vector<int>& rails) {
            sort(rails.begin(), rails.end());
            int top_streak = 1, current_row = 1;
            for (int i = 1; i < rails.size(); ++i) {
                current_row = (rails[i] == rails[i - 1] + 1) ? current_row + 1 : 1;
                top_streak = max(top_streak, current_row);
            }
            return top_streak + 1;
        };
        int side_len = min(get_gap(hBars), get_gap(vBars));
        return side_len * side_len;
    }
};

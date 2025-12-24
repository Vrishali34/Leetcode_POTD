class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total_fruit = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend());
        int used_bins = 0;
        for (int bin_vol : capacity) {
            total_fruit -= bin_vol;
            used_bins++;
            if (total_fruit <= 0) break;
        }
        return used_bins;
    }
};

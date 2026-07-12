class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& base_arr) {
        vector<int> sorted_items = base_arr;
        sort(sorted_items.begin(), sorted_items.end());
        sorted_items.erase(unique(sorted_items.begin(), sorted_items.end()), sorted_items.end());
        for (int &curr_val : base_arr) {
            curr_val = distance(sorted_items.begin(), lower_bound(sorted_items.begin(), sorted_items.end(), curr_val)) + 1;
        }
        return base_arr;
    }
};

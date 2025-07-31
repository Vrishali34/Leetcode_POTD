class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> unique_ors;
        unordered_set<int> ending_ors;
        for (int x : arr) {
            unordered_set<int> next_ending_ors;
            next_ending_ors.insert(x);
            for (int y : ending_ors) {
                next_ending_ors.insert(x | y);
            }
            ending_ors = next_ending_ors;
            for (int val : ending_ors) {
                unique_ors.insert(val);
            }
        }
        return unique_ors.size();
    }
};

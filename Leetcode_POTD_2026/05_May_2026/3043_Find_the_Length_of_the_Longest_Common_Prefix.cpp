class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> seen_pref;
        for (int base_val : arr1) {
            while (base_val > 0) {
                seen_pref.insert(base_val);
                base_val /= 10;
            }
        }
        int max_len = 0;
        for (int check_val : arr2) {
            while (check_val > 0) {
                if (seen_pref.count(check_val)) {
                    max_len = max(max_len, (int)to_string(check_val).length());
                    break;
                }
                check_val /= 10;
            }
        }
        return max_len;
    }
};

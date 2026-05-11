class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digit_flow;
        for (int val_entry : nums) {
            string val_str = to_string(val_entry);
            for (char unit_char : val_str) {
                digit_flow.push_back(unit_char - '0');
            }
        }
        return digit_flow;
    }
};

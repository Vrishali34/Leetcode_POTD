class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> groups_formed;
        for (int i = 0; i < s.length(); i += k) {
            string current_group = s.substr(i, k);
            if (current_group.length() < k) {
                current_group.append(k - current_group.length(), fill);
            }
            groups_formed.push_back(current_group);
        }
        return groups_formed;
    }
};

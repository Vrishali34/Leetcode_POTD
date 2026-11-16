class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string next_str;
            for (int i = 0; i < s.size(); i += k) {
                int group_sum = 0;
                for (int j = i; j < min((int)s.size(), i + k); j++)
                    group_sum += s[j] - '0';
                next_str += to_string(group_sum);
            }
            s = next_str;
        }
        return s;
    }
};

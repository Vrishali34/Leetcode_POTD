class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int len_s = s.size();
        vector<int> first_seen(26, -1), last_seen(26, -1);
        for (int idx = 0; idx < len_s; idx++) {
            int char_code = s[idx] - 'a';
            if (first_seen[char_code] == -1) first_seen[char_code] = idx;
            last_seen[char_code] = idx;
        }

        vector<pair<int, int>> range_list;
        for (int char_code = 0; char_code < 26; char_code++) {
            if (first_seen[char_code] == -1) continue;
            int left_bound = first_seen[char_code], right_bound = last_seen[char_code];
            for (int idx = left_bound; idx <= right_bound; idx++) {
                int other_char = s[idx] - 'a';
                left_bound = min(left_bound, first_seen[other_char]);
                if (last_seen[other_char] > right_bound) {
                    right_bound = last_seen[other_char];
                    idx = left_bound - 1;
                }
            }
            if (left_bound == first_seen[char_code])
                range_list.push_back({right_bound, left_bound});
        }

        sort(range_list.begin(), range_list.end());

        vector<string> result_list;
        int last_end = -1;
        for (auto& range_pair : range_list) {
            int right_bound = range_pair.first, left_bound = range_pair.second;
            if (left_bound > last_end) {
                result_list.push_back(s.substr(left_bound, right_bound - left_bound + 1));
                last_end = right_bound;
            }
        }

        return result_list;
    }
};

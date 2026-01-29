class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> char_map(26, vector<long long>(26, 1e18));
        for (int i = 0; i < 26; ++i) char_map[i][i] = 0;
        for (int i = 0; i < original.size(); ++i) {
            int u_char = original[i] - 'a', v_char = changed[i] - 'a';
            char_map[u_char][v_char] = min(char_map[u_char][v_char], (long long)cost[i]);
        }
        for (int mid_char = 0; mid_char < 26; ++mid_char)
            for (int src_char = 0; src_char < 26; ++src_char)
                for (int dst_char = 0; dst_char < 26; ++dst_char)
                    char_map[src_char][dst_char] = min(char_map[src_char][dst_char], char_map[src_char][mid_char] + char_map[mid_char][dst_char]);
        long long total_sum = 0;
        for (int i = 0; i < source.size(); ++i) {
            long long step_cost = char_map[source[i] - 'a'][target[i] - 'a'];
            if (step_cost >= 1e18) return -1;
            total_sum += step_cost;
        }
        return total_sum;
    }
};
